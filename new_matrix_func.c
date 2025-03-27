#include "new_matrix.h"
#include <stdio.h>
#include <string.h>



matrix_t* new_matrix(matrix_vtable_t* func, int rows, int cols, FieldInfo* type_element)
{
    if(rows <= 0 || cols <= 0) {
        printf("Ошибка: неправильно указан размер матрицы\n");
        exit(1);
    }

    matrix_t* z = (matrix_t*) malloc(sizeof(matrix_t));

    z->func = func;

    if (z == NULL || z->func == NULL) {
        printf("Ошибка: func == NULL\n");
        exit(1);
    }

    z->Type = type_element;
    
    z->data.rows = rows;
    z->data.cols = cols;
    
    //z->func->data_alloc(z);
    Either alloc_result = func->data_alloc(&(z->data));
    if (alloc_result.type == EITHER_ERROR) {
        printf("Ошибка: %s\n", alloc_result.value.error);
        either_free(&alloc_result);
        exit(1);
    }

    return z;
}

void _matrix_data_alloc(matrix_t* z)
{
    if(z == NULL) exit(1);
    z->func->data_alloc(&(z->data));
}

// char* toStringMatrix (matrix_t* z){
//     return z->func->toString(z);
// }

Either _free_matrix(matrix_t* z)
{
    if (z == NULL || z->func == NULL) {
        return either_error("Матрица пуста");
    }
    free(z->data.elem); 
    free(z);
    return either_success(NULL);
}

void FreeMatrix(matrix_t* z)
{
    Either elem1 = _free_matrix(z);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
}

Either _get_elem(matrix_t* z, int i, int j){
    if (!z) {
        return either_error("Матрица не инициализирована");
    }

    if (!z->data.elem) {
        return either_error("Элементы матрицы не инициализированы");
    }
    
    if (i < 0 || i >= z->data.rows || j < 0 || j >= z->data.cols) {
        return either_error("Индексы за пределами матрицы");
    }

    void* element = (char*)z->data.elem + (i * z->data.cols + j) * z->Type->size;
    return either_success(element);
}

void* Get(matrix_t* z, int i, int j) 
{
    Either elem1 = _get_elem(z, i, j);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
    return elem1.value.success;
}


//-----------Предотвращение ошибок в действиях над матрицами-----------
Either _add_matrix(matrix_t* a1, matrix_t* a2)
{
    if (a1 == NULL || a2 == NULL) {
        return either_error("Матрица не инициализирована");
    }

    if (a1->data.elem == NULL || a2->data.elem == NULL) {
        return either_error("Данные матриц не инициализированы");
    }

    if (a1->data.rows != a2->data.rows || a1->data.cols != a2->data.cols) {
        return either_error("Размеры матриц не совпадают");
    }

    if (a1->Type != a2->Type) {
        return either_error("Типы данных матриц не совпадают");
    }

    matrix_t* new = new_matrix(a1->func, a1->data.rows, a1->data.cols, a1->Type);
    for(int i = 0; i < a1->data.rows; i++)
    {
        for(int j = 0; j < a1->data.cols; j++)
        {
            new->Type->add(Get(a1, i, j), Get(a2, i, j), Get(new, i, j));
        }
    }
    return either_success(new);
}

Either _multi_matrix(matrix_t* a1, matrix_t* a2)
{
    if (a1 == NULL || a2 == NULL) {
        return either_error("Матрица не инициализирована");
    }

    if (a1->data.elem == NULL || a2->data.elem == NULL) {
        return either_error("Данные матриц не инициализированы");
    }

    if (a1->data.cols != a2->data.rows) {
        return either_error("Невозможно умножить матрицы, так как количество столбцов в первой матрице не равно количеству строк во второй матрице");
    }

    if (a1->Type != a2->Type) {
        return either_error("Типы данных матриц не совпадают");
    }

    matrix_t* new = new_matrix(a1->func, a1->data.rows, a2->data.cols, a1->Type);
    for(int i = 0; i < new->data.rows; i++)
    {
        for(int j = 0; j < new->data.cols; j++)
        {
            new->Type->zero(Get(new, i, j));
            for(int k = 0; k < a1->data.cols; k++)
            {
                void* elem1 = Get(a1, i, k);
                void* elem2 = Get(a2, k, j);

                void* multi_elem = malloc(a1->Type->size);
                a1->Type->multi(elem1, elem2, multi_elem);

                new->Type->add(Get(new, i, j), multi_elem, Get(new, i, j));
                free(multi_elem);
            }
        }
    }
    return either_success(new);
}

Either _multi_skalar(matrix_t* z, void* skal)
{
    if (z == NULL || skal == NULL) {
        return either_error("Матрица или элемент не инициализированы");
    }

    if (z->data.elem == NULL) {
        return either_error("Данные матриц не инициализированы");
    }

    matrix_t* new = new_matrix(z->func, z->data.rows, z->data.cols, z->Type);
    for(int i = 0; i < z->data.rows; i++){
        for(int j = 0; j < z->data.cols; j++){
            new->Type->multi(Get(z, i, j), skal, Get(new, i, j));
        }
    }
    return either_success(new);
}

Either _transposing(matrix_t* z)
{
    if (z == NULL) {
        return either_error("Матрица не инициализирована");
    }

    if (z->data.elem == NULL) {
        return either_error("Данные матриц не инициализированы");
    }
    matrix_t* new = new_matrix(z->func, z->data.cols, z->data.rows, z->Type);
    for(int i = 0; i < z->data.rows; i++)
    {
        for(int j = 0; j < z->data.cols; j++)
        {
            memcpy(Get(new, j, i), Get(z, i, j), new->Type->size);
        }
    }
    return either_success(new);

}

Either _to_string_matrix(matrix_t* z)
{
    if (z == NULL) {
        return either_error("Матрица не инициализирована");
    }

    if (z->data.elem == NULL) {
        return either_error("Данные матриц не инициализированы");
    }

    size_t buffer = 256; 
    char* buff = (char*)malloc(buffer);
    if (!buff) return either_success(NULL);

    int set = snprintf(buff, buffer, "Матрица %dx%d: \n[ ", z->data.rows, z->data.cols);

    for (int i = 0; i < z->data.rows; i++) {
        set += snprintf(buff + set, buffer - set, "{");
        for (int j = 0; j < z->data.cols; j++) {

            z->Type->write(Get(z, i, j), &set, &buff, &buffer);
            //set += snprintf(buff + set, buffer - set, "%s", z->Type->write(Get(z, i, j), set, buff, buffer));

            if (j < z->data.cols - 1) {
                set += snprintf(buff + set, buffer - set, ", ");
            }
        }
        set += snprintf(buff + set, buffer - set, "}");
        if (i < z->data.rows - 1) {
            set += snprintf(buff + set, buffer - set, " ");
        }
    }

    set += snprintf(buff + set, buffer - set, " ]\n");

    return either_success(buff);

}
//------------------------------


//-----------Действия над матрицами-----------
matrix_t* AddMatrix(matrix_t* a1, matrix_t* a2)
{
    Either elem1 = _add_matrix(a1, a2);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //return elem1.value.error;
    }
    return elem1.value.success;
}

matrix_t* MultiMatrix(matrix_t* a1, matrix_t* a2)
{
    Either elem1 = _multi_matrix(a1, a2);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
    return elem1.value.success;
}

matrix_t* MultiSkalar(matrix_t* z, void* skal)
{
    Either elem1 = _multi_skalar(z, skal);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
    return elem1.value.success;
}

matrix_t* Transposing(matrix_t* z)
{
    Either elem1 = _transposing(z);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
    return elem1.value.success;
}

char* toStringMatrix(matrix_t* z) 
{
    Either elem1 = _to_string_matrix(z);
    if (elem1.type == EITHER_ERROR) {
        fprintf(stderr, "Ошибка: %s\n", elem1.value.error);
        either_free(&elem1);
        //exit(EXIT_FAILURE);
    }
    return elem1.value.success;
}
//------------------------------


//-----------EITHER;)-----------
Either either_success(void* data) 
{
    Either result;
    result.type = EITHER_SUCCESS;
    result.value.success = data;
    return result;
}

Either either_error(const char* message) 
{
    Either result;
    result.type = EITHER_ERROR;
    result.value.error = strdup(message);
    return result;
}

void either_free(Either* either)
{
    if (either->type == EITHER_ERROR) {
        free(either->value.error);
    }
}
//------------------------------


//-----------ДЗ по линалу-----------
void DivDouble(void* a, void* b, void* result)
{
    if (((Double*)b)->value == 0) {
        printf("Ошибка: деление на ноль\n");
        //exit(EXIT_FAILURE);
    }
    ((Double*)result)->value =  ((Double*)a)->value / ((Double*)b)->value;
}

void SubDouble(void* a, void* b, void* result)
{
    ((Double*)result)->value = ((Double*)a)->value - ((Double*)b)->value;
}

void LU_Decomposition(matrix_t* A, matrix_t* L, matrix_t* U)
{
    if (A->data.rows != A->data.cols) {
        printf("\nОшибка: Матрица не является квадратной, LU-разложение невозможно.\n");
        //exit(EXIT_FAILURE);
    }
    
    int n = A->data.rows;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A->Type->zero(Get(L, i, j));
            A->Type->zero(Get(U, i, j));
        }
        ((Double*)Get(L, i, i))->value = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            void* sum = malloc(A->Type->size);
            A->Type->zero(sum);
            
            for (int k = 0; k < i; k++) {
                void* temp = malloc(A->Type->size);
                A->Type->multi(Get(L, i, k), Get(U, k, j), temp);
                A->Type->add(sum, temp, sum);
                free(temp);
            }
            SubDouble(Get(A, i, j), sum, Get(U, i, j));
            free(sum);
        }
        
        for (int j = i + 1; j < n; j++) {
            void* sum = malloc(A->Type->size);
            A->Type->zero(sum);
            
            for (int k = 0; k < i; k++) {
                void* temp = malloc(A->Type->size);
                A->Type->multi(Get(L, j, k), Get(U, k, i), temp);
                A->Type->add(sum, temp, sum);
                free(temp);
            }
            
            void* divisor = Get(U, i, i);
            void* numerator = malloc(A->Type->size);
            SubDouble(Get(A, j, i), sum, numerator);
            DivDouble(numerator, divisor, Get(L, j, i));
            
            free(numerator);
            free(sum);
        }
    }
}




//-----------Работа с файлами-----------
Either write_matrix_to_file_either(matrix_t* z, const char* filename, char* answer) {
    FILE* f = fopen(filename, "a");
    if (!f) return either_error("Не удалось открыть файл");
    fputs(answer, f);
    fclose(f);
    return either_success(NULL);
}

void write_matrix_to_file(matrix_t* z, const char* filename, char* answer){
    Either examp = write_matrix_to_file_either(z, filename, answer);
    if(examp.type == EITHER_ERROR){
        fprintf(stderr, "Ошибка: %s\n", examp.value.error);
        either_free(&examp);
    }
}


