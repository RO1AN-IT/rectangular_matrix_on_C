#include "../new_matrix.h"
#include <stdio.h>
#include <string.h>
#include "FLOAT.h"
#include "../FieldInfo.h"

static matrix_vtable_t* float_table = NULL;

FieldInfo FloatType = {
    .multi = MultiFloat,
    .add = AddFloat,
    .size = sizeof(Float),
    .zero = ZeroFloat,
    .write = WriteFloat
};

matrix_vtable_t* get_table_matrix_Float()
{
    if(float_table == NULL)
    {
        float_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        //float_table->toString = &_toStringMatrixFloat;
        float_table->data_alloc = &_matrix_data_alloc_float;
        float_table->Input = &_input_float;
    }
    return float_table;
}

Either _input_elem_float(matrix_t* z, int i, int j, void* elem)
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

    Float* temp = (Float*)(z->data.elem) + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(Float));

    return either_success(NULL);
}

void _input_float(matrix_t* z, int i, int j, void* elem)
{
    Either elem1 = _input_elem_float(z, i, j, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _matrix_data_alloc_float(matrix_data_t* z) 
{
    z->elem = malloc(sizeof(Float) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для элементов");
    }

    return either_success(NULL); 
}


Either _add_float(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Float*)elem)->value = ((Float*)a1)->value + ((Float*)a2)->value;
    return either_success(NULL);
}

void AddFloat(void* a1, void* a2, void* elem)
{
    Either elem1 = _add_float(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _multi_float(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Float*)elem)->value = ((Float*)a1)->value * ((Float*)a2)->value;
    return either_success(NULL);
}

void MultiFloat(void* a1, void* a2, void* elem)
{
    Either elem1 = _multi_float(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _zero_float(void* elem)
{
    if (elem == NULL) {
        return either_error("Указатель равен NULL");
    }

    ((Float*)elem)->value = 0;
    return either_success(NULL);
}

void ZeroFloat(void* elem)
{
    Either elem1 = _zero_float(elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _write_float(void* a, int* set, char** buff, size_t* len_buff)
{
    if (a == NULL || set == NULL || buff == NULL || len_buff == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    if (*set < 0 || *len_buff <= 0 || *set >= *len_buff) {
        return either_error("Некорректный размер буфера");
    }

    Float* elem = (Float*)a;
    *set += snprintf(*buff + *set, *len_buff - *set, "%.2f", elem->value);

    return either_success(NULL);
}

void WriteFloat(void* a, int* set, char** buff, size_t* len_buff)
{
    Either elem1 = _write_float(a, set, buff, len_buff);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

FieldInfo* get_type_element_Float()
{
    return &FloatType;
} 
