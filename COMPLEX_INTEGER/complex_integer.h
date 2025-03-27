#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"

typedef struct complex_INT 
{
    int Re;
    int Im;
}complex_integer;

void AddComplexInteger(void* a1, void* a2, void* elem);
void MultiComplexInteger(void* a1, void* a2, void* elem);
void ZeroComplexInteger(void* elem);
void WriteComplexInteger(void* a, int* set, char** buff, size_t* len_buff);

