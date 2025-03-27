#include "../new_matrix.h"
#include <stdio.h>
#include <string.h>
#include "DOUBLE.h"
#include "../FieldInfo.h"

static matrix_vtable_t* double_table = NULL;

FieldInfo DoubleType = {
    .multi = MultiDouble,
    .add = AddDouble,
    .size = sizeof(Double),
    .zero = ZeroDouble,
    .write = WriteDouble
};

matrix_vtable_t* get_table_matrix_Double()
{
    if(double_table == NULL)
    {
        double_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        //double_table->toString = &_toStringMatrixDouble;
        double_table->data_alloc = &_matrix_data_alloc_double;
        double_table->Input = &_input_double;
    }
    return double_table;
}

Either _input_elem_double(matrix_t* z, int i, int j, void* elem)
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

    Double* temp = (Double*)(z->data.elem) + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(Double));

    return either_success(NULL);

}

void _input_double(matrix_t* z, int i, int j, void* elem)
{
    Either elem1 = _input_elem_double(z, i, j, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _matrix_data_alloc_double(matrix_data_t* z) {
    z->elem = malloc(sizeof(Double) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для элементов");
    }

    return either_success(NULL);
}


Either _add_double(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Double*)elem)->value = ((Double*)a1)->value + ((Double*)a2)->value;
    return either_success(NULL);
}

void AddDouble(void* a1, void* a2, void* elem)
{
    Either elem1 = _add_double(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _multi_double(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Double*)elem)->value = ((Double*)a1)->value * ((Double*)a2)->value;
    return either_success(NULL);
}

void MultiDouble(void* a1, void* a2, void* elem)
{
    Either elem1 = _multi_double(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _zero_double(void* elem)
{
    if (elem == NULL) {
        return either_error("Указатель равен NULL");
    }

    ((Double*)elem)->value = 0.0;
    return either_success(NULL);
}

void ZeroDouble(void* elem)
{
    Either elem1 = _zero_double(elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _write_double(void* a, int* set, char** buff, size_t* len_buff)
{
    if (a == NULL || set == NULL || buff == NULL || len_buff == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    if (*set < 0 || *len_buff <= 0 || *set >= *len_buff) {
        return either_error("Некорректный размер буфера");
    }

    Double* elem = (Double*)a;
    *set += snprintf(*buff + *set, *len_buff - *set, "%.4lf", elem->value);

    return either_success(NULL);
}

void WriteDouble(void* a, int* set, char** buff, size_t* len_buff)
{
    Either elem1 = _write_double(a, set, buff, len_buff);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

FieldInfo* get_type_element_Double()
{
    return &DoubleType;
} 
