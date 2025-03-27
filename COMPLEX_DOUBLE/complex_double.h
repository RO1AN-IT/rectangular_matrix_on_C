#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"


typedef struct complex_DOUB 
{
    double Re;
    double Im;
}complex_double;

void AddComplexDouble(void* a1, void* a2, void* elem);
void MultiComplexDouble(void* a1, void* a2, void* elem);
void ZeroComplexDouble(void* elem);
void WriteComplexDouble(void* a, int* set, char** buff, size_t* len_buff);

