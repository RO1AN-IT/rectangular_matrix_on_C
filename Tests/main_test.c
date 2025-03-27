#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "INT_TEST/INT_test.h"  
#include "FLOAT_TEST/FLOAT_test.h"
#include "DOUBLE_TEST/DOUBLE_test.h"  
#include "COMPLEX_INTEGER_TEST/COMPLEX_INTEGER_test.h"
#include "COMPLEX_DOUBLE_TEST/COMPLEX_DOUBLE_test.h"
#include "Test.h"              

int main(void) {
    Test test = {0};
    char buffer[256];
    char* filename = "/Users/rodionduktanov/Desktop/предметы/Пары_по_с++/пара1/АТД/лаба_1/new_draft_laba_1/Tests/out_test.txt";
    FILE* file_out = fopen(filename, "w");
    fclose(file_out);
    
    printf("\n~~~~~~~~~~~~~~ ТЕСТЫ для INT ~~~~~~~~~~~~~~\n");
    FILE* file_int = fopen("Tests/INT_TEST/test_integer.txt", "r");
    file_out = fopen(filename, "a");
    fputs("~~~~~~~~~~~~~~ РЕЗУЛЬТАТЫ для INT ~~~~~~~~~~~~~~\n", file_out);
    fclose(file_out);

    if (file_int == NULL) {
        fprintf(stderr, "Ошибка открытия файла для INT-тестов!\n");
        return EXIT_FAILURE;
    }
    
    while (fgets(buffer, sizeof(buffer), file_int) != NULL) {
        if (strcmp(buffer, "SUM_INTEGER_MATRIX\n") == 0) {
            printf("\n|===========Сложение матриц============|\n");
            int rows, cols;
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows, &cols) != 2) {
                fprintf(stderr, "Неверный формат размеров матрицы!\n");
                break;
            }
            printf("Размер матриц: %dx%d\n", rows, cols);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_integer_test(&matrix1, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_integer_test(&matrix2, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* result = NULL;
            add_matrix_integer_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            
            
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_INTEGER_MATRIX\n") == 0) {
            printf("\n|===========Умножение матриц===========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 1: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_integer_test(&matrix1, rows1, cols1, buffer, &test);
            
            int rows2, cols2;
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows2, &cols2) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 2: %dx%d\n", rows2, cols2);

            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_integer_test(&matrix2, rows2, cols2, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* result = NULL;
            multi_matrix_integer_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "TRANSPOSING_INTEGER_MATRIX\n") == 0) {
            printf("\n|=======Транспонирование матрицы=======|\n");
            
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_integer_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* result = NULL;
            transposing_matrix_integer_test(matrix1, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_SKALAR_INTEGER_MATRIX\n") == 0) {
            printf("\n|==========Умножение на скаляр=========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_integer_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            Integer skal;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d", &skal.value) != 1) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }

            if (fgets(buffer, sizeof(buffer), file_int) == NULL) break;
            matrix_t* result = NULL;
            skal_matrix_integer_test(matrix1, &skal, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    
    printf("\n~~~~~~~~~~~~~~ ТЕСТЫ для FLOAT ~~~~~~~~~~~~~~\n");
    FILE* file_float = fopen("Tests/FLOAT_TEST/test_float.txt", "r");
    file_out = fopen(filename, "a");
    fputs("~~~~~~~~~~~~~~ РЕЗУЛЬТАТЫ для FLOAT ~~~~~~~~~~~~~~\n", file_out);
    fclose(file_out);

    if (file_float == NULL) {
        fprintf(stderr, "Ошибка открытия файла для FLOAT-тестов!\n");
        return EXIT_FAILURE;
    }
    
    while (fgets(buffer, sizeof(buffer), file_float) != NULL) {
        if (strcmp(buffer, "SUM_FLOAT_MATRIX\n") == 0) {
            printf("\n|===========Сложение матриц============|\n");
            int rows, cols;
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows, &cols) != 2) {
                fprintf(stderr, "Неверный формат размеров матрицы!\n");
                break;
            }
            printf("Размер матриц: %dx%d\n", rows, cols);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_float_test(&matrix1, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_float_test(&matrix2, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* result = NULL;
            add_matrix_float_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            
            
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_FLOAT_MATRIX\n") == 0) {
            printf("\n|===========Умножение матриц===========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 1: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_float_test(&matrix1, rows1, cols1, buffer, &test);
            
            int rows2, cols2;
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows2, &cols2) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 2: %dx%d\n", rows2, cols2);

            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_float_test(&matrix2, rows2, cols2, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* result = NULL;
            multi_matrix_float_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "TRANSPOSING_FLOAT_MATRIX\n") == 0) {
            printf("\n|=======Транспонирование матрицы=======|\n");
            
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_float_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* result = NULL;
            transposing_matrix_float_test(matrix1, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_SKALAR_FLOAT_MATRIX\n") == 0) {
            printf("\n|==========Умножение на скаляр=========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_float_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            Float skal;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%f", &skal.value) != 1) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }

            if (fgets(buffer, sizeof(buffer), file_float) == NULL) break;
            matrix_t* result = NULL;
            skal_matrix_float_test(matrix1, &skal, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
    printf("\n~~~~~~~~~~~~~~ ТЕСТЫ для DOUBLE ~~~~~~~~~~~~~~\n");
    FILE* file_double = fopen("Tests/DOUBLE_TEST/test_double.txt", "r");
    file_out = fopen(filename, "a");
    fputs("~~~~~~~~~~~~~~ РЕЗУЛЬТАТЫ для DOUBLE ~~~~~~~~~~~~~~\n", file_out);
    fclose(file_out);

    if (file_double == NULL) {
        fprintf(stderr, "Ошибка открытия файла для DOUBLE-тестов!\n");
        return EXIT_FAILURE;
    }
    
    while (fgets(buffer, sizeof(buffer), file_double) != NULL) {
        if (strcmp(buffer, "SUM_DOUBLE_MATRIX\n") == 0) {
            printf("\n|===========Сложение матриц============|\n");
            int rows, cols;
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows, &cols) != 2) {
                fprintf(stderr, "Неверный формат размеров матрицы!\n");
                break;
            }
            printf("Размер матриц: %dx%d\n", rows, cols);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_double_test(&matrix1, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_double_test(&matrix2, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* result = NULL;
            add_matrix_double_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            
            
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_DOUBLE_MATRIX\n") == 0) {
            printf("\n|===========Умножение матриц===========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 1: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_double_test(&matrix1, rows1, cols1, buffer, &test);
            
            int rows2, cols2;
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows2, &cols2) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 2: %dx%d\n", rows2, cols2);

            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_double_test(&matrix2, rows2, cols2, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* result = NULL;
            multi_matrix_double_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "TRANSPOSING_DOUBLE_MATRIX\n") == 0) {
            printf("\n|=======Транспонирование матрицы=======|\n");
            
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_double_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* result = NULL;
            transposing_matrix_double_test(matrix1, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_SKALAR_DOUBLE_MATRIX\n") == 0) {
            printf("\n|==========Умножение на скаляр=========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_double_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            Double skal;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%lf", &skal.value) != 1) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }

            if (fgets(buffer, sizeof(buffer), file_double) == NULL) break;
            matrix_t* result = NULL;
            skal_matrix_double_test(matrix1, &skal, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
    printf("\n~~~~~~~~~~~~~~ ТЕСТЫ для COMPLEX_INTEGER ~~~~~~~~~~~~~~\n");
    FILE* file_complex_integer = fopen("Tests/COMPLEX_INTEGER_TEST/test_complex_integer.txt", "r");
    file_out = fopen(filename, "a");
    fputs("~~~~~~~~~~~~~~ РЕЗУЛЬТАТЫ для COMPLEX_INTEGER ~~~~~~~~~~~~~~\n", file_out);
    fclose(file_out);

    if (file_complex_integer == NULL) {
        fprintf(stderr, "Ошибка открытия файла для COMPLEX_INTEGER-тестов!\n");
        return EXIT_FAILURE;
    }
    
    while (fgets(buffer, sizeof(buffer), file_complex_integer) != NULL) {
        if (strcmp(buffer, "SUM_COMPLEX_INTEGER_MATRIX\n") == 0) {
            printf("\n|===========Сложение матриц============|\n");
            int rows, cols;
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows, &cols) != 2) {
                fprintf(stderr, "Неверный формат размеров матрицы!\n");
                break;
            }
            printf("Размер матриц: %dx%d\n", rows, cols);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_integer_test(&matrix1, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_complex_integer_test(&matrix2, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* result = NULL;
            add_matrix_complex_integer_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            
            
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_COMPLEX_INTEGER_MATRIX\n") == 0) {
            printf("\n|===========Умножение матриц===========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 1: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_integer_test(&matrix1, rows1, cols1, buffer, &test);
            
            int rows2, cols2;
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows2, &cols2) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 2: %dx%d\n", rows2, cols2);

            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_complex_integer_test(&matrix2, rows2, cols2, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* result = NULL;
            multi_matrix_complex_integer_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "TRANSPOSING_COMPLEX_INTEGER_MATRIX\n") == 0) {
            printf("\n|=======Транспонирование матрицы=======|\n");
            
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_integer_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* result = NULL;
            transposing_matrix_complex_integer_test(matrix1, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_SKALAR_COMPLEX_INTEGER_MATRIX\n") == 0) {
            printf("\n|==========Умножение на скаляр=========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_integer_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            complex_integer skal;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "(%d+%di)", &skal.Re, &skal.Im) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }

            if (fgets(buffer, sizeof(buffer), file_complex_integer) == NULL) break;
            matrix_t* result = NULL;
            skal_matrix_complex_integer_test(matrix1, &skal, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
    printf("\n~~~~~~~~~~~~~~ ТЕСТЫ для COMPLEX_DOUBLE ~~~~~~~~~~~~~~\n");
    FILE* file_complex_double = fopen("Tests/COMPLEX_DOUBLE_TEST/test_complex_double.txt", "r");
    file_out = fopen(filename, "a");
    fputs("~~~~~~~~~~~~~~ РЕЗУЛЬТАТЫ для COMPLEX_DOUBLE ~~~~~~~~~~~~~~\n", file_out);
    fclose(file_out);

    if (file_complex_double == NULL) {
        fprintf(stderr, "Ошибка открытия файла для COMPLEX_DOUBLE-тестов!\n");
        return EXIT_FAILURE;
    }
    
    while (fgets(buffer, sizeof(buffer), file_complex_double) != NULL) {
        if (strcmp(buffer, "SUM_COMPLEX_DOUBLE_MATRIX\n") == 0) {
            printf("\n|===========Сложение матриц============|\n");
            int rows, cols;
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows, &cols) != 2) {
                fprintf(stderr, "Неверный формат размеров матрицы!\n");
                break;
            }
            printf("Размер матриц: %dx%d\n", rows, cols);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_double_test(&matrix1, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_complex_double_test(&matrix2, rows, cols, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* result = NULL;
            add_matrix_complex_double_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            
            
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_COMPLEX_DOUBLE_MATRIX\n") == 0) {
            printf("\n|===========Умножение матриц===========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 1: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_double_test(&matrix1, rows1, cols1, buffer, &test);
            
            int rows2, cols2;
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows2, &cols2) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы 2: %dx%d\n", rows2, cols2);

            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix2 = NULL;
            fil_matrix_complex_double_test(&matrix2, rows2, cols2, buffer, &test);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* result = NULL;
            multi_matrix_complex_double_test(matrix1, matrix2, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(matrix2);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "TRANSPOSING_COMPLEX_DOUBLE_MATRIX\n") == 0) {
            printf("\n|=======Транспонирование матрицы=======|\n");
            
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_double_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* result = NULL;
            transposing_matrix_complex_double_test(matrix1, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
        if (strcmp(buffer, "MULTI_SKALAR_COMPLEX_DOUBLE_MATRIX\n") == 0) {
            printf("\n|==========Умножение на скаляр=========|\n");
            int rows1, cols1;
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d %d", &rows1, &cols1) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }
            printf("Размер матрицы: %dx%d\n", rows1, cols1);
            
            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* matrix1 = NULL;
            fil_matrix_complex_double_test(&matrix1, rows1, cols1, buffer, &test);

            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            complex_double skal;
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "(%lf+%lfi)", &skal.Re, &skal.Im) != 2) {
                fprintf(stderr, "Неверный формат размера матрицы!\n");
                break;
            }

            if (fgets(buffer, sizeof(buffer), file_complex_double) == NULL) break;
            matrix_t* result = NULL;
            skal_matrix_complex_double_test(matrix1, &skal, &result, buffer, &test);

            FreeMatrix(matrix1);
            FreeMatrix(result);
            printf("|======================================|\n");
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    fclose(file_float);
    fclose(file_double);
    fclose(file_int);
    fclose(file_complex_integer);
    fclose(file_complex_double);
    final_report(&test);
    return EXIT_SUCCESS;
}
