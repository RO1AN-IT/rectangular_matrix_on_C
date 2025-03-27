#include "complex_integer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"
#include "../new_matrix.h"

static matrix_vtable_t* complex_integer_table = NULL;

FieldInfo ComplexIntegerType = {
    .multi = MultiComplexInteger,
    .add = AddComplexInteger,
    .size = sizeof(complex_integer),
    .zero = ZeroComplexInteger,
    .write = WriteComplexInteger
};


Either _add_complex_integer(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((complex_integer*)elem)->Re = (((complex_integer*)a1)->Re + ((complex_integer*)a2)->Re);
    ((complex_integer*)elem)->Im = ((complex_integer*)a1)->Im + ((complex_integer*)a2)->Im;
    return either_success(NULL);
}

void AddComplexInteger(void* a1, void* a2, void* elem)
{
    Either elem1 = _add_complex_integer(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _multi_complex_integer(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((complex_integer*)elem)->Re = (((complex_integer*)a1)->Re * ((complex_integer*)a2)->Re) - (((complex_integer*)a1)->Im * ((complex_integer*)a2)->Im);
    ((complex_integer*)elem)->Im = (((complex_integer*)a1)->Re * ((complex_integer*)a2)->Im) + (((complex_integer*)a1)->Im * ((complex_integer*)a2)->Re);
    return either_success(NULL);
}

void MultiComplexInteger(void* a1, void* a2, void* elem)
{
    Either elem1 = _multi_complex_integer(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _zero_complex_integer(void* elem)
{
    if (elem == NULL) {
        return either_error("Указатель равен NULL");
    }

    ((complex_integer*)elem)->Im = 0;
    ((complex_integer*)elem)->Re = 0;
    return either_success(NULL);
}

void ZeroComplexInteger(void* elem)
{
    Either elem1 = _zero_complex_integer(elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _write_complex_integer(void* a, int* set, char** buff, size_t* len_buff)
{
    if (a == NULL || set == NULL || buff == NULL || len_buff == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    if (*set < 0 || *len_buff <= 0 || *set >= *len_buff) {
        return either_error("Некорректный размер буфера");
    }

    complex_integer* elem = (complex_integer*)a;
    *set += snprintf(*buff + *set, *len_buff - *set, "(%d+%di)", elem->Re, elem->Im);

    return either_success(NULL);
}

void WriteComplexInteger(void* a, int* set, char** buff, size_t* len_buff)
{
    Either elem1 = _write_complex_integer(a, set, buff, len_buff);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr,  "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

FieldInfo* get_type_element_complex_integer()
{
    return &ComplexIntegerType;
} 


Either _matrix_data_alloc_complex_integer(matrix_data_t* z) {
    z->elem = malloc(sizeof(complex_integer) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для элементов");
    }

    return either_success(NULL); 
}

matrix_vtable_t* get_table_matrix_complex_integer()
{
    if(complex_integer_table == NULL)
    {
        complex_integer_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        //complex_integer_table->toString = &_toStringMatrixInt;
        complex_integer_table->data_alloc = &_matrix_data_alloc_complex_integer;
        complex_integer_table->Input = &_input_complex_integer;
    }
    return complex_integer_table;
}

Either _input_elem_complex_integer(matrix_t* z, int i, int j, void* elem)
{
    if (z == NULL) {
        return either_error("Матрица не инициализирована");
    }
    if (z->data.elem == NULL) {
        return either_error("Данные матрицы не инициализирована");
    }
    if (elem == NULL) {
        return either_error("Элемент для записи не инициализирован");
    }

    if (i < 0 || i >= z->data.rows || j < 0 || j >= z->data.cols) {
        return either_error("Индексы за пределами матрицы");
    }

    complex_integer* temp = (complex_integer*)z->data.elem + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(complex_integer));

    return either_success(NULL);

}

void _input_complex_integer(matrix_t* z, int i, int j, void* elem)
{
    Either elem1 = _input_elem_complex_integer(z, i, j, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}
