#pragma once


#include <stdlib.h>
#include <stdio.h>


typedef struct FieldInfo_t {
    size_t size;
    void (*add) (void*, void*, void*);
    void (*multi) (void*, void*, void*);
    void (*zero) (void*);
    void (*write) (void*, int*, char**, size_t*);
} FieldInfo;
