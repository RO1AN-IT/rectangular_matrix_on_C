#pragma once //единичный запуск // #pragma once - если файл уже подключен, то не подключать его еще раз
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"

//таблица функций описывает функции, которые будут использоваться в структуре
/*typedef struct complex //указывам название структуры если хотим к ней обратиться в структуре, а так можно не указывать
{
    float Re;
    float Im;
}complex_t;*/

#define complex_new(name, type, elem_re, elem_im) Complex* name = new_complex(get_table_complex_##type(), get_type_element_##type(), elem_re, elem_im);


typedef struct _complex_data //указывам название структуры если хотим к ней обратиться в структуре, а так можно не указывать
{
    void* Re;
    void* Im;
    FieldInfo* type_element;
}complex_data_t;

struct complex ;
//typedef char *(*toString_complex_t) (struct complex*); 
// typedef char *(*toString_complex_t) (struct complex*);
typedef void (*data_alloc_complex_t) (struct _complex_data*);
typedef void (*input_complex) (struct complex*, void*, void*); 

typedef struct _complex_vtable
{
    // toString_complex_t toString;//указатель на комплексную функцию
    data_alloc_complex_t data_alloc;
    input_complex Input;
}complex_vtable_t;

typedef struct complex
{
    complex_data_t data;
    complex_vtable_t* funcs;
}Complex;

// char *toStringComplex (void* z);
// char* WriteComplexFloat (Complex* z);
// char* WriteComplexInt (Complex* z);

Complex* new_complex(complex_vtable_t* funcs, FieldInfo* type_element, void* elem_re, void* elem_im);

void _complex_data_alloc(Complex* z);//выделяем память под данные

void _complex_data_alloc_int(complex_data_t* data);

void _complex_data_alloc_double(complex_data_t* data);

complex_vtable_t* get_table_complex_Integer();

complex_vtable_t* get_table_complex_Double();

void _input_int_complex(Complex* z, void* elem_re, void* elem_im);
void _input_double_complex(Complex* z, void* elem_re, void* elem_im);

void FreeComplex(Complex* z);

Complex* complex_copy(const Complex* src);

//complex_vtable_t int_vtable = {.toString = &_toStringInt, .data_alloc = &_complex_data_alloc_int};//экземпляр структуры - указатель на функцию
//complex_vtable_t float_vtale = {.toString = &_toStringFloat, .data_alloc = &_complex_data_alloc_float};//.data_alloc - указатель на функцию 

//complex_t* new_complex_empty();
//complex_t* new_complex_from_float(float Re, float Im);
//complex_t* new_complex(complex_t* z);

/*#define new_complex() _new_complex_empty()
#define new_complex(x) _new_complex_empty(x)
#define new_complex(x,y) _new_complex_empty(x,y)*/

// Complex* AddComplex(Complex* a1, Complex* a2);
// Complex* MultiComplex(Complex* a1, Complex* a2);
// Complex* ZeroComplex(Complex* a1);

void AddComplex(void* a1, void* a2, void* elem);
void MultiComplex(void* a1, void* a2, void* elem);
void ZeroComplex(void* elem);
void WriteComplex (void* z, int* set, char** buff, size_t* len_buff);

// complex_t* complex_sub(complex_t* left, complex_t* right);
// complex_t* complex_div(complex_t* left, complex_t* right);
// complex_t* complex_conj(complex_t* z);
// complex_t* complex_neg(complex_t* z);


//Either<V,E>
//Optional<T> 