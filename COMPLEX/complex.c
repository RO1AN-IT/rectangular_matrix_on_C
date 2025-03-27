#include "../new_matrix.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"
#include "complex.h"
// #include "../DOUBLE/DOUBLE.h"
// #include "../INT/INT.h"

FieldInfo ComplexType = {
    .multi = MultiComplex,
    .add = AddComplex,
    .size = sizeof(Complex),
    .zero = ZeroComplex,
    .write = WriteComplex
};

static complex_vtable_t* int_table_complex = NULL; //static - переменная будет видна только в этом файле
static complex_vtable_t* double_table_complex = NULL;
static matrix_vtable_t* complex_table = NULL;

/*complex_t* new_complex_empty(){
    complex_t* z = (complex_t*) malloc(sizeof(complex_t));
    z->Re = 0.;
    z->Im = 0.;

    return z;
}

complex_t* new_complex_from_float(float Re, float Im){
    complex_t* z = (complex_t*) malloc(sizeof(complex_t));
    z->Re = Re;
    z->Im = Im;

    return z;
}

complex_t* new_complex(complex_t* other){
    complex_t* z = (complex_t*) malloc(sizeof(complex_t));
    z->Re = other->Re;
    z->Im = other->Re;

    return z;
}*/


// complex_t* complex_add(complex_t* left, complex_t* right){}
// complex_t* complex_sub(complex_t* left, complex_t* right){}
// complex_t* complex_mul(complex_t* left, complex_t* right){}
// complex_t* complex_div(complex_t* left, complex_t* right){}
// complex_t* complex_conj(complex_t* z){}
// complex_t* complex_neg(complex_t* z){}

void WriteComplex (void* z, int* set, char** buff, size_t* len_buff) {
    Complex* elem = (Complex*)z;
    *set += snprintf(*buff + *set, *len_buff - *set, "("); 
    elem->data.type_element->write(elem->data.Re, set, buff, len_buff);
    *set += snprintf(*buff + *set, *len_buff - *set, " + ");
    elem->data.type_element->write(elem->data.Im, set, buff, len_buff);
    *set += snprintf(*buff + *set, *len_buff - *set, "i)");
}

Complex* new_complex(complex_vtable_t* funcs, FieldInfo* type_element, void* elem_re, void* elem_im){    
    Complex* z = (Complex*) malloc(sizeof(Complex));
    z->funcs = funcs;
    z->data.type_element = type_element; 
    z->funcs->data_alloc(&(z->data));
    z->funcs->Input(z, elem_re, elem_im);
    return z;
}

void _complex_data_alloc(Complex* z){//выделяем память под данные
    if(z == NULL) exit(1);
    z->funcs->data_alloc(&(z->data));
}

void _complex_data_alloc_int(complex_data_t* data){
    data->Re = malloc(sizeof(Integer));
    data->Im = malloc(sizeof(Integer));
}

void _complex_data_alloc_double(complex_data_t* data){
    data->Re = malloc(sizeof(Double));
    data->Im = malloc(sizeof(Double));
}


complex_vtable_t* get_table_complex_Integer(){ //получаем таблицу для int - если ее нет, то создаем - иначе возвращаем - чтобы не создавать каждый раз
    if(int_table_complex == NULL){
        int_table_complex = (complex_vtable_t*) malloc(sizeof(complex_vtable_t));
        //int_table_complex->toString = &WriteComplexInt;
        int_table_complex->data_alloc = &_complex_data_alloc_int;
        int_table_complex->Input = &_input_int_complex;
    }
    return int_table_complex;
}

complex_vtable_t* get_table_complex_Double(){
    if(double_table_complex == NULL){
        double_table_complex = (complex_vtable_t*) malloc(sizeof(complex_vtable_t));
        //double_table_complex->toString = &WriteComplexDouble;
        double_table_complex->data_alloc = &_complex_data_alloc_double;
        double_table_complex->Input = &_input_double_complex;

    }
    return double_table_complex;
}

void _input_int_complex(Complex* z, void* elem_re, void* elem_im)
{
    ((Integer*)(z->data.Re))->value = ((Integer*)elem_re)->value;
    ((Integer*)(z->data.Im))->value = ((Integer*)elem_im)->value;
}

void _input_double_complex(Complex* z, void* elem_re, void* elem_im)
{
    ((Double*)(z->data.Re))->value = ((Double*)elem_re)->value;
    ((Double*)(z->data.Im))->value = ((Double*)elem_im)->value;
}

void FreeComplex(Complex* z)
{
    free(z->data.Re);
    free(z->data.Im);
}



matrix_vtable_t* get_table_matrix_Complex()
{
    if(complex_table == NULL)
    {
        complex_table = (matrix_vtable_t*) malloc(sizeof(matrix_vtable_t));
        //complex_table->toString = &_toStringMatrixComplex;
        complex_table->data_alloc = &_matrix_data_alloc_complex;
        complex_table->Input = &_input_complex;
    }
    return complex_table;
}

void _input_complex(matrix_t* z, int i, int j, void* elem)
{
    Complex* temp = (Complex*)(z->data.elem) + i * z->data.cols + j;
    memcpy(temp, elem, sizeof(Complex));
}

Either _matrix_data_alloc_complex(matrix_data_t* z) {
    z->elem = malloc(sizeof(Complex) * z->rows * z->cols);
    if (!z->elem) {
        return either_error("Ошибка выделения памяти для строк");
    }

    return either_success(NULL);
}

void AddComplex(void* a1, void* a2, void* elem) {
    ((Complex*)elem)->data.type_element->add(((Complex*)a1)->data.Im, ((Complex*)a2)->data.Im,((Complex*)elem)->data.Im);
    ((Complex*)elem)->data.type_element->add(((Complex*)a1)->data.Re, ((Complex*)a2)->data.Re,((Complex*)elem)->data.Re);
}

void MultiComplex(void* a1, void* a2, void* elem) {
    ((Complex*)elem)->data.type_element->multi(((Complex*)a1)->data.Im, ((Complex*)a2)->data.Im,((Complex*)elem)->data.Im);
    ((Complex*)elem)->data.type_element->multi(((Complex*)a1)->data.Re, ((Complex*)a2)->data.Re,((Complex*)elem)->data.Re);
}

void ZeroComplex(void* elem) {
    ((Complex*)elem)->data.type_element->zero(((Complex*)elem)->data.Im);
    ((Complex*)elem)->data.type_element->zero(((Complex*)elem)->data.Re);
}


FieldInfo* get_type_element_Complex(){
    return &ComplexType;
} 


// char* _toStringMatrixComplex(matrix_t* z) {
//     size_t buffer = 100; 
//     char* buff = (char*) malloc(buffer);
//     if (!buff) return NULL;

//     int set = snprintf(buff, buffer, "Матрица %dx%d: [ ", z->data.rows, z->data.cols);

//     for (int i = 0; i < z->data.rows; i++) {
//         set += snprintf(buff + set, buffer - set, "{");
//         for (int j = 0; j < z->data.cols; j++) {

//             Complex* temp = (Complex*)(z->data.elem) + i * z->data.cols + j;
//             set += snprintf(buff + set, buffer - set, "%s", temp);

//             if (j < z->data.cols - 1) {
//                 set += snprintf(buff + set, buffer - set, ", ");
//             }
//         }
//         set += snprintf(buff + set, buffer - set, "}");
//         if (i < z->data.rows - 1) {
//             set += snprintf(buff + set, buffer - set, " ");
//         }
//     }

//     set += snprintf(buff + set, buffer - set, " ]");

//     return buff;
// }





// char* _toStringMatrixComplex(matrix* z) {
//     size_t buffer = 100; 
//     char* buff = (char*)malloc(buffer);
//     if (!buff) return NULL;

//     int set = snprintf(buff, buffer, "Матрица %dx%d: [ ", z->data.rows, z->data.cols);

//     for (int i = 0; i < z->data.rows; i++) {
//         set += snprintf(buff + set, buffer - set, "{");
//         for (int j = 0; j < z->data.cols; j++) {

//             complex_t* temp = (complex_t*)z->data.elem + i * z->data.cols + j;
//             set += snprintf(buff + set, buffer - set, "%d + %di", temp->data.Im, temp->data.Re);

//             if (j < z->data.cols - 1) {
//                 set += snprintf(buff + set, buffer - set, ", ");
//             }
//         }
//         set += snprintf(buff + set, buffer - set, "}");
//         if (i < z->data.rows - 1) {
//             set += snprintf(buff + set, buffer - set, " ");
//         }
//     }

//     set += snprintf(buff + set, buffer - set, " ]");

//     return buff;
// }


































//конструкторы в ооп - это функции, которые создают объекты и инициализируют их 
//геттеры в  ооп - это функции, которые возвращают значения полей объекта
//сеттеры в ооп - это функции, которые устанавливают значения полей объекта