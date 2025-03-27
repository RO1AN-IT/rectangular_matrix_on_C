#include "Test.h"

int compare_var(const char* real, const char* expect) {
    if(strcmp(real, expect) == 0) return 1;
    return 0;
}

void final_report(Test* test) {
    printf("------ Итоговый отчет ------\n");
    printf("Общее количество тестов: %d\n", test->total);
    printf("Корректно пройдено: %d\n", test->passed);
    printf("Провалено: %d\n", test->failed);
}
