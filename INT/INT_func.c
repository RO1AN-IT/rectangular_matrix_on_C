#include "../new_matrix.h"
#include <stdio.h>
#include <string.h>
#include "INT.h"
#include "../FieldInfo.h"

static matrix_vtable_t* int_table = NULL;

FieldInfo IntType = {
    .multi = MultiInteger,
    .add = AddInteger,
    .size = sizeof(Integer),
    .zero = ZeroInteger,
    .write = WriteInteger 
};

matrix_vtable_t* get_table_matrix_Integer()
{
    if(int_table == NULL)
    {
        int_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        int_table->data_alloc = &_matrix_data_alloc_int;
        int_table->Input = &_input_int;
    }
    return int_table;
}

Either _input_elem_int(matrix_t* z, int i, int j, void* elem)
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

    Integer* temp = (Integer*)z->data.elem + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(Integer));

    return either_success(NULL);

}

void _input_int(matrix_t* z, int i, int j, void* elem)
{
    Either elem1 = _input_elem_int(z, i, j, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _matrix_data_alloc_int(matrix_data_t* z) 
{
    z->elem = malloc(sizeof(Integer) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для элементов строк");
    }
    return either_success(NULL);
}


Either _add_integer(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Integer*)elem)->value = ((Integer*)a1)->value + ((Integer*)a2)->value;
    return either_success(NULL);
}

void AddInteger(void* a1, void* a2, void* elem)
{
    Either elem1 = _add_integer(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        exit(1);
    }
}

Either _multi_integer(void* a1, void* a2, void* elem)
{
    if (a1 == NULL || a2 == NULL || elem == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    ((Integer*)elem)->value = ((Integer*)a1)->value * ((Integer*)a2)->value;
    return either_success(NULL);
}

void MultiInteger(void* a1, void* a2, void* elem)
{
    Either elem1 = _multi_integer(a1, a2, elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _zero_integer(void* elem)
{
    if (elem == NULL) {
        return either_error("Указатель равен NULL");
    }

    ((Integer*)elem)->value = 0;
    return either_success(NULL);
}

void ZeroInteger(void* elem)
{
    Either elem1 = _zero_integer(elem);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _write_integer(void* a, int* set, char** buff, size_t* len_buff)
{
    if (a == NULL || set == NULL || buff == NULL || len_buff == NULL) {
        return either_error("Один из указателей равен NULL");
    }

    if (*set < 0 || *len_buff <= 0 || *set >= *len_buff) {
        return either_error("Некорректный размер буфера");
    }

    Integer* elem = (Integer*)a;
    *set += snprintf(*buff + *set, *len_buff - *set, "%d", elem->value);

    return either_success(NULL);
}

void WriteInteger(void* a, int* set, char** buff, size_t* len_buff)
{
    Either elem1 = _write_integer(a, set, buff, len_buff);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

FieldInfo* get_type_element_Integer()
{
    return &IntType;
} 

