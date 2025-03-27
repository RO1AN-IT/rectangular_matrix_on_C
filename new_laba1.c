#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "new_matrix.h"


int main(void){
    printf("Введите размер матрицы 1: ");
    int r1,c1;
    scanf("%d  %d", &r1, &c1);
    matrix(examp1, Double, r1, c1);
    printf("Адрес матрицы 1: %p\n", (void*)&examp1);
    printf("Размеры матрицы 1: %d x %d\n", examp1->data.rows, examp1->data.cols);
    printf("Введите элементы матрицы 1: ");
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
        {
            Double a;
            scanf("%lf", &a.value);
            //scanf("%d", &elem.value);
            Push_elem(examp1, i, j, a);
        } 
    } 

    printf("Введите размер матрицы 2: ");
    int r2,c2;
    scanf("%d  %d", &r2, &c2);
    matrix(examp2, Double, r2, c2);
    printf("Адрес матрицы 2: %p\n", (void*)&examp2);
    printf("Размеры матрицы 2: %d x %d\n", examp2->data.rows, examp2->data.cols);
    printf("Введите элементы матрицы 2: ");
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            Double elem;
            scanf("%lf", &elem.value);
            Push_elem(examp2, i, j, elem);
        }
    } 
    

    //printf("%d", (int)examp->data.elem + 1 * examp->data.cols + 1);

    // char* answer = toStringMatrix(examp1);
    // printf("\n1 %s",answer);
    // free(answer);
    // printf("\n2 %s",toStringMatrix(examp2));

    // complex_double skal;
    // scanf("%lf %lf", &skal.Re, &skal.Im);
    // matrix_t* examp_compl = Transposing(examp1);
    // printf("\n2 %s",toStringMatrix(examp_compl));

    // matrix(L, Double, r2, r2);
    // matrix(U, Double, r2, r2);
    // LU_Decomposition(examp2, L, U);
    // printf("\nLU-разложение Матрицы 2: \nМатрица L: %s",toStringMatrix(L));
    // printf("\nМатрица U: %s",toStringMatrix(U));

    // Integer skal;
    // printf("\nВведите скаляр: ");
    // scanf("%d", &skal.value);
    // matrix_t* examp_skal = MultiSkalar(examp2, &skal);
    // printf("\nМатрица 2 умноженная на скаляр: %s",toStringMatrix(examp_skal));
    // matrix_t* examp_transponir = Transposing(examp1);
    // printf("\n1 Транспонированная %s",toStringMatrix(examp_transponir));
    //matrix* examp_sum = AddMatrix(examp1, examp2);
    // matrix_t* examp_multi = MultiMatrix(examp1, examp2);
    // printf("\nСумма матриц: %s",toStringMatrix(examp_multi));
    // FreeMatrix(examp1);
    // FreeMatrix(examp2);
    //Free(examp_multi);
    printf("\nМатрица очищена!");
    return EXIT_SUCCESS;
}


//   while(1){
//         printf("\n----------МЕНЮ----------\n");
//         printf("1)Сложить матрицы;\n");
//         printf("2)Умножить матрицы;\n");
//         printf("3)Транспонировать матрицу;\n");
//         printf("4)Умножить на скаляр;\n");
//         printf("5)LU-разложение;\n");
//         printf("6)Выход.");
//         printf("\n------------------------\n");
//         int var;
//         printf("Выберете опцию: ");
//         scanf("%d", var);
//         if(var > 6 || var < 1){
//             continue;
//         }
//         switch (var)
//         {
//             case 1:
//                 printf("\n----------Тип данных----------\n");
//                 printf("1)Integer;\n");
//                 printf("2)Float;\n");
//                 printf("3)Double;\n");
//                 printf("4)Complex_integer;\n");
//                 printf("5)Complex_double;\n");
//                 printf("6)Выход.");
//                 printf("\n------------------------------\n");
//                 int var_type;
//                 printf("Выберете тип: ");
//                 scanf("%d", var_type);
//                 if(var_type > 6 || var_type < 1){
//                     continue;
//                 }
//                 switch (var_type)
//                 {
//                     case 1:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Integer, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Integer a;
//                                 scanf("%d", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Integer, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Integer elem;
//                                 scanf("%d", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* sum_integer = AddMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(sum_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(sum_integer);
//                         break;

//                     case 2:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Float, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Float a;
//                                 scanf("%f", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Float, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Float elem;
//                                 scanf("%f", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* sum_float = AddMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(sum_float);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(sum_float);
//                         break;

//                     case 3:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Double, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Double a;
//                                 scanf("%lf", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Double, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Double elem;
//                                 scanf("%lf", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* sum_double = AddMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(sum_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(sum_double);
//                         break;
                            
//                     case 4:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_integer, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_integer a;
//                                 scanf("%d %d", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, complex_integer, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 complex_integer elem;
//                                 scanf("%d %d", &elem.Re, &elem.Im);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* sum_complex_integer = AddMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(sum_complex_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(sum_complex_integer);
//                         break;

//                     case 5:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_double, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_double a;
//                                 scanf("%lf %lf", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, complex_double, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 complex_double elem;
//                                 scanf("%lf %lf", &elem.Re, &elem.Im);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* sum_complex_double = AddMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(sum_complex_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(sum_complex_double);
//                         break;
                    
//                     case 6:
//                         break;
//                 }
//                 break;

//             case 2:
//                 printf("\n----------Тип данных----------\n");
//                 printf("1)Integer;\n");
//                 printf("2)Float;\n");
//                 printf("3)Double;\n");
//                 printf("4)Complex_integer;\n");
//                 printf("5)Complex_double;\n");
//                 printf("6)Выход.");
//                 printf("\n------------------------------\n");
//                 int var_type;
//                 printf("Выберете тип: ");
//                 scanf("%d", var_type);
//                 if(var_type > 6 || var_type < 1){
//                     continue;
//                 }
//                 switch (var_type)
//                 {
//                     case 1:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Integer, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Integer a;
//                                 scanf("%d", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Integer, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Integer elem;
//                                 scanf("%d", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* multi_integer = MultiMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(multi_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(multi_integer);
//                         break;

//                     case 2:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Float, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Float a;
//                                 scanf("%f", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Float, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Float elem;
//                                 scanf("%f", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* multi_float = MultiMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(multi_float);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(multi_float);
//                         break;

//                     case 3:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Double, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Double a;
//                                 scanf("%lf", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, Double, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 Double elem;
//                                 scanf("%lf", &elem.value);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* multi_double = MultiMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(multi_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(multi_double);
//                         break;
                            
//                     case 4:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_integer, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_integer a;
//                                 scanf("%d %d", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, complex_integer, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 complex_integer elem;
//                                 scanf("%d %d", &elem.Re, &elem.Im);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* multi_complex_integer = MultiMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(multi_complex_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(multi_complex_integer);
//                         break;

//                     case 5:
//                         printf("Введите размер матрицы 1: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_double, r1, c1);
//                         printf("Введите элементы матрицы 1: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_double a;
//                                 scanf("%lf %lf", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
                    
//                         printf("Введите размер матрицы 2: ");
//                         int r2,c2;
//                         scanf("%d  %d", &r2, &c2);
//                         matrix(examp2, complex_double, r2, c2);
//                         printf("Введите элементы матрицы 2: ");
//                         for(int i = 0; i < r2; i++)
//                         {
//                             for(int j = 0; j < c2; j++)
//                             {
//                                 complex_double elem;
//                                 scanf("%lf %lf", &elem.Re, &elem.Im);
//                                 Push_elem(examp2, i, j, elem);
//                             }
//                         } 
//                         matrix_t* multi_complex_double = MultiMatrix(examp1, examp2);
//                         char* answer = toStringMatrix(multi_complex_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(examp2);
//                         FreeMatrix(multi_complex_double);
//                         break;
                    
//                     case 6:
//                         break;
//                 }
//                 break;

//             case 3:
//                 printf("\n----------Тип данных----------\n");
//                 printf("1)Integer;\n");
//                 printf("2)Float;\n");
//                 printf("3)Double;\n");
//                 printf("4)Complex_integer;\n");
//                 printf("5)Complex_double;\n");
//                 printf("6)Выход.");
//                 printf("\n------------------------------\n");
//                 int var_type;
//                 printf("Выберете тип: ");
//                 scanf("%d", var_type);
//                 if(var_type > 6 || var_type < 1){
//                     continue;
//                 }
//                 switch (var_type)
//                 {
//                     case 1:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Integer, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Integer a;
//                                 scanf("%d", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         matrix_t* transpon_integer = Transposing(examp1);
//                         char* answer = toStringMatrix(transpon_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(transpon_integer);
//                         break;

//                     case 2:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Float, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Float a;
//                                 scanf("%f", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         matrix_t* transpon_float = Transposing(examp1);
//                         char* answer = toStringMatrix(transpon_float);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(transpon_float);
//                         break;

//                     case 3:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Double, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Double a;
//                                 scanf("%lf", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         }
//                         matrix_t* transpon_double = Transposing(examp1);
//                         char* answer = toStringMatrix(transpon_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(transpon_double);
//                         break;
                            
//                     case 4:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_integer, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_integer a;
//                                 scanf("%d %d", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         matrix_t* transpon_complex_integer = Transposing(examp1);
//                         char* answer = toStringMatrix(transpon_complex_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(transpon_complex_integer);
//                         break;

//                     case 5:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_double, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_double a;
//                                 scanf("%lf %lf", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         }
//                         matrix_t* transpon_complex_double = Transposing(examp1);
//                         char* answer = toStringMatrix(transpon_complex_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(transpon_complex_double);
//                         break;
                    
//                     case 6:
//                         break;
//                 }
//                 break;
            
//             case 4:
//                 printf("\n----------Тип данных----------\n");
//                 printf("1)Integer;\n");
//                 printf("2)Float;\n");
//                 printf("3)Double;\n");
//                 printf("4)Complex_integer;\n");
//                 printf("5)Complex_double;\n");
//                 printf("6)Выход.");
//                 printf("\n------------------------------\n");
//                 int var_type;
//                 printf("Выберете тип: ");
//                 scanf("%d", var_type);
//                 if(var_type > 6 || var_type < 1){
//                     continue;
//                 }
//                 switch (var_type)
//                 {
//                     case 1:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Integer, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Integer a;
//                                 scanf("%d", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         printf("\nВведите скаляр: ");
//                         Integer* skal_int;
//                         scanf("%d", &skal_int->value);
//                         matrix_t* skal_integer = MultiSkalar(examp1, skal_int);
//                         char* answer = toStringMatrix(skal_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(skal_integer);
//                         break;

//                     case 2:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Float, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Float a;
//                                 scanf("%f", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         printf("\nВведите скаляр: ");
//                         Float* skal_fl;
//                         scanf("%f", &skal_fl->value);
//                         matrix_t* skal_float = MultiSkalar(examp1, skal_fl);
//                         char* answer = toStringMatrix(skal_float);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(skal_float);
//                         break;

//                     case 3:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, Double, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 Double a;
//                                 scanf("%lf", &a.value);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         }
//                         printf("\nВведите скаляр: ");
//                         Double* skal_doub;
//                         scanf("%lf", &skal_doub->value);
//                         matrix_t* skal_double = MultiSkalar(examp1, skal_doub);
//                         char* answer = toStringMatrix(skal_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(skal_double);
//                         break;
                            
//                     case 4:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_integer, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_integer a;
//                                 scanf("%d %d", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         } 
//                         printf("\nВведите скаляр: ");
//                         complex_integer* skal_compl_int;
//                         scanf("%d %d", &skal_compl_int->Re, &skal_compl_int->Im);
//                         matrix_t* skal_complex_integer = MultiSkalar(examp1, skal_compl_int);
//                         char* answer = toStringMatrix(skal_complex_integer);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(skal_complex_integer);
//                         break;

//                     case 5:
//                         printf("Введите размер матрицы: ");
//                         int r1,c1;
//                         scanf("%d  %d", &r1, &c1);
//                         matrix(examp1, complex_double, r1, c1);
//                         printf("Введите элементы матрицы: ");
//                         for(int i = 0; i < r1; i++)
//                         {
//                             for(int j = 0; j < c1; j++)
//                             {
//                                 complex_double a;
//                                 scanf("%lf %lf", &a.Re, &a.Im);
//                                 Push_elem(examp1, i, j, a);
//                             } 
//                         }
//                         printf("\nВведите скаляр: ");
//                         complex_double* skal_compl_doub;
//                         scanf("%lf %lf", &skal_compl_doub->Re, &skal_compl_doub->Im);
//                         matrix_t* skal_complex_double = MultiSkalar(examp1, skal_compl_doub);
//                         char* answer = toStringMatrix(skal_complex_double);
//                         printf("\nОтвет: %s",answer);
//                         free(answer);
//                         FreeMatrix(examp1);
//                         FreeMatrix(skal_complex_double);
//                         break;
//                     case 6:
//                         break;
//                 }
//                 break;
//             case 5:
//                 break;
//             case 6:
//                 exit(0);
//                 break;
//         }

//     }














