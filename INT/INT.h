#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include "../FieldInfo.h"


typedef struct Integer{
    int value;
} Integer;

void AddInteger(void* a1, void* a2, void* elem);
void MultiInteger(void* a1, void* a2, void* elem);
void ZeroInteger(void* elem);
void WriteInteger(void* a, int* set, char** buff, size_t* len_buff);

