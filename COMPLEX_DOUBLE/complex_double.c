#include "../new_matrix.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"
#include "complex_double.h"

static matrix_vtable_t* complex_double_table = NULL;

FieldInfo ComplexDoubleType = {
    .multi = MultiComplexDouble,
    .add = AddComplexDouble,
    .size = sizeof(complex_double),
    .zero = ZeroComplexDouble,
    .write = WriteComplexDouble
};


Either _add_complex_double(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((complex_double*)elem)->Re = (((complex_double*)a1)->Re + ((complex_double*)a2)->Re);
    ((complex_double*)elem)->Im = ((complex_double*)a1)->Im + ((complex_double*)a2)->Im;
    return either_success(NULL);
}

void AddComplexDouble(void* a1, void* a2, void* elem)
{
    Either elem1 = _add_complex_double(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _multi_complex_double(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((complex_double*)elem)->Re = (((complex_double*)a1)->Re * ((complex_double*)a2)->Re) - (((complex_double*)a1)->Im * ((complex_double*)a2)->Im);
    ((complex_double*)elem)->Im = (((complex_double*)a1)->Re * ((complex_double*)a2)->Im) + (((complex_double*)a1)->Im * ((complex_double*)a2)->Re);
    return either_success(NULL);
}

void MultiComplexDouble(void* a1, void* a2, void* elem)
{
    Either elem1 = _multi_complex_double(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _zero_complex_double(void* elem)
{
    if (elem == NULL) {
        return either_error("Указатель равен NULL");
    }

    ((complex_double*)elem)->Im = 0.0;
    ((complex_double*)elem)->Re = 0.0;
    return either_success(NULL);
}

void ZeroComplexDouble(void* elem)
{
    Either elem1 = _zero_complex_double(elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _write_complex_double(void* a, int* set, char** buff, size_t* len_buff)
{
    if (a == NULL || set == NULL || buff == NULL || len_buff == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    if (*set < 0 || *len_buff <= 0 || *set >= *len_buff) {
        return either_error("Некорректный размер буфера");
    }

    complex_double* elem = (complex_double*)a;
    *set += snprintf(*buff + *set, *len_buff - *set, "(%.3lf+%.3lfi)", elem->Re, elem->Im);

    return either_success(NULL);
}

void WriteComplexDouble(void* a, int* set, char** buff, size_t* len_buff)
{
    Either elem1 = _write_complex_double(a, set, buff, len_buff);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr,  "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

FieldInfo* get_type_element_complex_double()
{
    return &ComplexDoubleType;
} 



Either _matrix_data_alloc_complex_double(matrix_data_t* z) {
    z->elem = malloc(sizeof(complex_double) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для элементов");
    }

    return either_success(NULL); 
}

matrix_vtable_t* get_table_matrix_complex_double()
{
    if(complex_double_table == NULL)
    {
        complex_double_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        //complex_double_table->toString = &_toStringMatrixInt;
        complex_double_table->data_alloc = &_matrix_data_alloc_complex_double;
        complex_double_table->Input = &_input_complex_double;
    }
    return complex_double_table;
}

Either _input_elem_complex_double(matrix_t* z, int i, int j, void* elem)
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

    complex_double* temp = (complex_double*)z->data.elem + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(complex_double));

    return either_success(NULL);

}

void _input_complex_double(matrix_t* z, int i, int j, void* elem)
{
    Either elem1 = _input_elem_complex_double(z, i, j, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}
