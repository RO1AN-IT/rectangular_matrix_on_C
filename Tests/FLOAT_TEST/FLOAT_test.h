#pragma once
#include "../Test.h"

void fil_matrix_float_test(matrix_t** z, int rows, int cols, char* buffer, Test* test);
Either fil_matrix_float_test_either(matrix_t** z, int rows, int cols, char* buffer, Test* test);
void add_matrix_float_test(matrix_t* a1, matrix_t* a2, matrix_t** resul, char* buffer, Test* test);
void multi_matrix_float_test(matrix_t* a1, matrix_t* a2, matrix_t** resul, char* buffer, Test* test);
void transposing_matrix_float_test(matrix_t* a1, matrix_t** resul, char* buffer, Test* test);
void skal_matrix_float_test(matrix_t* a1, Float* skal, matrix_t** resul, char* buffer, Test* test);