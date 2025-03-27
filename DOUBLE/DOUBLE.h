#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"

typedef struct Double{
    double value;
} Double;

void AddDouble(void* a1, void* a2, void* elem);
void MultiDouble(void* a1, void* a2, void* elem);
void ZeroDouble(void* elem);
void WriteDouble(void* a, int* set, char** buff, size_t* len_buff);
