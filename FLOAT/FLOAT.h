#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"


typedef struct Float{
    float value;
} Float;

void AddFloat(void* a1, void* a2, void* elem);
void MultiFloat(void* a1, void* a2, void* elem);
void ZeroFloat(void* elem);
void WriteFloat(void* a, int* set, char** buff, size_t* len_buff);
