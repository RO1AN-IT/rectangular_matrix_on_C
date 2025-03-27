#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "COMPLEX/complex.h"
#include "COMPLEX_DOUBLE/complex_double.h"
#include "COMPLEX_INTEGER/complex_integer.h"
#include "INT/INT.h"
#include "FLOAT/FLOAT.h"
#include "DOUBLE/DOUBLE.h"
#include "FieldInfo.h"


#define matrix(name, type, rows, cols) matrix_t *name = new_matrix(get_table_matrix_##type(),rows,cols,get_type_element_##type())
#define Push_elem(name, row, col, elem) name->func->Input(name, row, col, &elem);

struct matrix;
struct _matrix_data;

typedef enum{ 
    EITHER_SUCCESS,
    EITHER_ERROR
}either_type;

typedef struct either_element{
    either_type type;   
    union {
        void* success;
        char* error;
    } value;
}Either;

typedef Either (*data_alloc_t) (struct _matrix_data*); 
typedef void (*input_matrix) (struct matrix*, int, int, void*);   

typedef struct _matrix_data{
    int rows,cols;
    void* elem;
} matrix_data_t;

typedef struct _matrix_vtable{
    data_alloc_t data_alloc;
    input_matrix Input;
} matrix_vtable_t;

typedef struct matrix{
    matrix_data_t data;
    matrix_vtable_t* func;
    const FieldInfo* Type;
} matrix_t;

char *toStringMatrix(matrix_t* z);

matrix_t* new_matrix(matrix_vtable_t* func, int rows, int cols, FieldInfo* type);

Either _get_elem(matrix_t* z, int i, int j);
void* Get(matrix_t* z, int i, int j);

matrix_t* AddMatrix(matrix_t* a1, matrix_t* a2);
matrix_t* MultiMatrix(matrix_t* a1, matrix_t* a2);
matrix_t* Transposing(matrix_t* z);
matrix_t* MultiSkalar(matrix_t* z, void* skal);

Either either_success(void* data);
Either either_error(const char* data);
void either_free(Either* data);

void FreeMatrix(matrix_t* z);





//---------Double---------
matrix_vtable_t* get_table_matrix_Double();
FieldInfo* get_type_element_Double();
void _input_double(matrix_t* z, int i, int j, void* elem);
Either _matrix_data_alloc_double(matrix_data_t* z);
Either _add_double(void* a1, void* a2, void* elem);
Either _multi_double(void* a1, void* a2, void* elem);
Either _zero_double(void* elem);
Either _write_double(void* a, int* set, char** buff, size_t* len_buff);


//---------Integer---------
matrix_vtable_t* get_table_matrix_Integer();
FieldInfo* get_type_element_Integer();
void _input_int(matrix_t* z, int i, int j, void* elem);
Either _matrix_data_alloc_int(matrix_data_t* z);
Either _add_integer(void* a1, void* a2, void* elem);
Either _multi_integer(void* a1, void* a2, void* elem);
Either _zero_integer(void* elem);
Either _write_integer(void* a, int* set, char** buff, size_t* len_buff);


//---------Float---------
matrix_vtable_t* get_table_matrix_Float();
FieldInfo* get_type_element_Float();
void _input_float(matrix_t* z, int i, int j, void* elem);
Either _matrix_data_alloc_float(matrix_data_t* z);
Either _add_float(void* a1, void* a2, void* elem);
Either _multi_float(void* a1, void* a2, void* elem);
Either _zero_float(void* elem);
Either _write_float(void* a, int* set, char** buff, size_t* len_buff);


//---------complex_double---------
matrix_vtable_t* get_table_matrix_complex_double();
FieldInfo* get_type_element_complex_double();
void _input_complex_double(matrix_t* z, int i, int j, void* elem);
Either _matrix_data_alloc_complex_double(matrix_data_t* z);
Either _add_complex_double(void* a1, void* a2, void* elem);
Either _multi_complex_double(void* a1, void* a2, void* elem);
Either _zero_complex_double(void* elem);
Either _write_complex_double(void* a, int* set, char** buff, size_t* len_buff);


//---------complex_integer---------
matrix_vtable_t* get_table_matrix_complex_integer();
FieldInfo* get_type_element_complex_integer();
void _input_complex_integer(matrix_t* z, int i, int j, void* elem);
Either _matrix_data_alloc_complex_integer(matrix_data_t* z);
Either _add_complex_integer(void* a1, void* a2, void* elem);
Either _multi_complex_integer(void* a1, void* a2, void* elem);
Either _zero_complex_integer(void* elem);
Either _write_complex_integer(void* a, int* set, char** buff, size_t* len_buff);






//-----------ДЗ по линалу-----------

void DivDouble(void* a, void* b, void* result);
void LU_Decomposition(matrix_t* A, matrix_t* L, matrix_t* U);
void SubDouble(void* a, void* b, void* result);




//-----------Файлы-----------

Either write_matrix_to_file_either(matrix_t* z, const char* filename, char* answer);
void write_matrix_to_file(matrix_t* z, const char* filename, char* answer);