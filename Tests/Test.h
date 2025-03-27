#pragma once
#include "../new_matrix.h"  
#include <stdio.h>
#include <string.h>


typedef struct MatrixTest {
    int total;
    int passed;
    int failed;
    const char* current_test;
} Test;


#define TEST_START(test) printf("\n[Тест] %s\n", __func__); \
    (test)->current_test = __func__; 

#define TEST_END(test) printf("\nИтог: correct = %d, fail = %d\n--------------------------------------\n", (test)->passed, (test)->failed); 


#define TEST_ASSERT(condition, msg, test)  (test)->total++; \
    if (condition) { \
        (test)->passed++; \
        printf("[Успешно]: %s\n", msg); \
    } else { \
        (test)->failed++; \
        printf("[Ошибка]: %s, file: %s, function: %s, line: %d\n", msg, __FILE__, __func__, __LINE__); \
    } 

#define TEST_FILE(current, standard, test) if (!compare_var(current, standard)) { \
        TEST_ASSERT(0, "Ответы отличаются", test); \
    } else { \
        TEST_ASSERT(1, "Ответы сошлись", test); \
    } 

int compare_var(const char* real, const char* expect);
void final_report(Test* test);
