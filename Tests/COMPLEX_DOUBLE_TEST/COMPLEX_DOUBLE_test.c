#include "COMPLEX_DOUBLE_test.h"
#include "../Test.h"
#include <stdlib.h>
#include <stdio.h>


Either fil_matrix_complex_double_test_either(matrix_t** z, int rows, int cols, char* buffer, Test* test) {
    TEST_START(test);

    *z = new_matrix(get_table_matrix_complex_double(), rows, cols, get_type_element_complex_double());
    TEST_ASSERT(*z != NULL, "Создание матрицы", test);
    
    buffer[strcspn(buffer, "\n")] = '\0';
    char* token = strtok(buffer, " ");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            complex_double elem;
            if (token == NULL) {
                return either_error("Недостаточно элементов в строке");
            }
            if (sscanf(token, "(%lf+%lfi)", &elem.Re, &elem.Im) != 2) {
                return either_error("Ошибка при чтении элемента");
            }
            Push_elem((*z), i, j, elem);
            token = strtok(NULL, " ");
        }
    }
    
    TEST_END(test);
    return either_success(*z);
}


void fil_matrix_complex_double_test(matrix_t** z, int rows, int cols, char* buffer, Test* test) {
    Either examp = fil_matrix_complex_double_test_either(z, rows, cols, buffer, test);
    if (examp.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", examp.value.error);
        either_free(&examp);
    }
}

void add_matrix_complex_double_test(matrix_t* a1, matrix_t* a2, matrix_t** resul, char* buffer, Test* test) {
    TEST_START(test);

    *resul = AddMatrix(a1, a2);
    TEST_ASSERT(*resul != NULL, "Сложение матриц", test);

    char* result = toStringMatrix(*resul);
    const char* head = "Сумма матриц:\n";

    const char* filename = "/Users/rodionduktanov/Desktop/предметы/Пары_по_с++/пара1/АТД/лаба_1/new_draft_laba_1/Tests/out_test.txt";
    char* out = (char*)malloc(strlen(head) + strlen(result) + 1);
    if (out == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для записи результата!\n");
        free(result);
        TEST_ASSERT(0, "Выделение памяти", test);
        return;
    }
    strcpy(out, head);
    strcat(out, result);
    write_matrix_to_file(*resul, filename, out);
    
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Ошибка открытия файла с результатом!\n");
        free(result);
        free(out);
        TEST_ASSERT(0, "Открытие файла с результатом", test);
        return;
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), f) != NULL){
        buff[strcspn(buff, "\n")] = '\0';
        if(strcmp(buff, "Сумма матриц:\n") == 0) break;
    }
    fgets(buff, sizeof(buff), f);
    fgets(buff, sizeof(buff), f);   
    buff[strcspn(buff, "\n")] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    TEST_FILE(buff, buffer, test);
    fclose(f);
    free(result);
    free(out);
    TEST_END(test);
}

void multi_matrix_complex_double_test(matrix_t* a1, matrix_t* a2, matrix_t** resul, char* buffer, Test* test) {
    TEST_START(test);

    *resul = MultiMatrix(a1, a2);
    TEST_ASSERT(*resul != NULL, "Умножение матриц", test);

    char* result = toStringMatrix(*resul);
    const char* head = "Произведение матриц:\n";

    const char* filename = "/Users/rodionduktanov/Desktop/предметы/Пары_по_с++/пара1/АТД/лаба_1/new_draft_laba_1/Tests/out_test.txt";
    char* out = (char*)malloc(strlen(head) + strlen(result) + 1);
    if (out == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для записи результата!\n");
        free(result);
        TEST_ASSERT(0, "Выделение памяти", test);
        return;
    }
    strcpy(out, head);
    strcat(out, result);
    write_matrix_to_file(*resul, filename, out);
    
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Ошибка открытия файла с результатом!\n");
        free(result);
        free(out);
        TEST_ASSERT(0, "Открытие файла с результатом", test);
        return;
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), f) != NULL){
        buff[strcspn(buff, "\n")] = '\0';
        if(strcmp(buff, "Произведение матриц:\n") == 0) break;
    }
    fgets(buff, sizeof(buff), f);
    fgets(buff, sizeof(buff), f);
    buff[strcspn(buff, "\n")] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    TEST_FILE(buff, buffer, test);
    fclose(f);
    free(result);
    free(out);
    TEST_END(test);
}

void transposing_matrix_complex_double_test(matrix_t* a1, matrix_t** resul, char* buffer, Test* test) {
    TEST_START(test);

    *resul = Transposing(a1);
    TEST_ASSERT(*resul != NULL, "Транспонирование матрицы", test);

    char* result = toStringMatrix(*resul);
    const char* head = "Транспонирование матрицы:\n";

    const char* filename = "/Users/rodionduktanov/Desktop/предметы/Пары_по_с++/пара1/АТД/лаба_1/new_draft_laba_1/Tests/out_test.txt";
    char* out = (char*)malloc(strlen(head) + strlen(result) + 1);
    if (out == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для записи результата!\n");
        free(result);
        TEST_ASSERT(0, "Выделение памяти", test);
        return;
    }
    strcpy(out, head);
    strcat(out, result);
    write_matrix_to_file(*resul, filename, out);
    
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Ошибка открытия файла с результатом!\n");
        free(result);
        free(out);
        TEST_ASSERT(0, "Открытие файла с результатом", test);
        return;
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), f) != NULL){
        buff[strcspn(buff, "\n")] = '\0';
        if(strcmp(buff, "Транспонирование матрицы:\n") == 0) break;
    }
    fgets(buff, sizeof(buff), f);
    fgets(buff, sizeof(buff), f); 
    buff[strcspn(buff, "\n")] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    TEST_FILE(buff, buffer, test);
    fclose(f);
    free(result);
    free(out);
    TEST_END(test);
}

void skal_matrix_complex_double_test(matrix_t* a1, complex_double* skal, matrix_t** resul, char* buffer, Test* test) {
    TEST_START(test);

    *resul = MultiSkalar(a1, skal);
    TEST_ASSERT(*resul != NULL, "Умножение матрицы на скаляр", test);

    char* result = toStringMatrix(*resul);
    const char* head = "Умножение матрицы на скаляр:\n";

    const char* filename = "/Users/rodionduktanov/Desktop/предметы/Пары_по_с++/пара1/АТД/лаба_1/new_draft_laba_1/Tests/out_test.txt";
    char* out = (char*)malloc(strlen(head) + strlen(result) + 1);
    if (out == NULL) {
        fprintf(stderr, "Ошибка выделения памяти для записи результата!\n");
        free(result);
        TEST_ASSERT(0, "Выделение памяти", test);
        return;
    }
    strcpy(out, head);
    strcat(out, result);
    write_matrix_to_file(*resul, filename, out);
    
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Ошибка открытия файла с результатом!\n");
        free(result);
        free(out);
        TEST_ASSERT(0, "Открытие файла с результатом", test);
        return;
    }
    char buff[256];
    while(fgets(buff, sizeof(buff), f) != NULL){
        buff[strcspn(buff, "\n")] = '\0';
        if(strcmp(buff, "Умножение матрицы на скаляр:\n") == 0) break;
    }
    fgets(buff, sizeof(buff), f);
    fgets(buff, sizeof(buff), f);
    buff[strcspn(buff, "\n")] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    TEST_FILE(buff, buffer, test);
    fclose(f);
    free(result);
    free(out);
    TEST_END(test);
}