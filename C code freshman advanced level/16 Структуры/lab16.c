#include <stdio.h>
#include <string.h>

struct Employee {
    char surname[50];
    char name[50];
    int department;
    float salary;
    float bonus;
    float taxes;
};

int main() {
    int k;
    scanf("%d",&k);
    struct Employee employees[k];
    int i, lowest_salary_department = 1, highest_salary_department = 2;
    float lowest_salary = 1000000.0, highest_salary = -1000000.0;

    // Заполнение массива структур данными
    for (i = 0; i < k; i++) {
        scanf("%s", employees[i].surname);
        scanf("%s", employees[i].name);
        scanf("%d", &employees[i].department);
        scanf("%f", &employees[i].salary);
        scanf("%f", &employees[i].bonus);
        scanf("%f", &employees[i].taxes);
    }

    // Поиск сотрудника с наименьшей зарплатой в первом отделе
    for (i = 0; i < k; i++) {
        if (employees[i].department == 1 && employees[i].salary + employees[i].bonus - employees[i].taxes < lowest_salary) {
            lowest_salary = employees[i].salary + employees[i].bonus - employees[i].taxes;
            lowest_salary_department = employees[i].department;
        }
    }

    // Поиск сотрудника с наибольшей зарплатой во втором отделе
    for (i = 0; i < k; i++) {
        if (employees[i].department == 2 && employees[i].salary + employees[i].bonus - employees[i].taxes > highest_salary) {
            highest_salary = employees[i].salary + employees[i].bonus - employees[i].taxes;
            highest_salary_department = employees[i].department;
        }
    }

    // Вывод результатов
    printf("\n");
    for (i = 0; i < k; i++) {
        printf("%-15s %-15s %-5d %-15.0f %-15.0f %-15.0f\n", employees[i].surname, employees[i].name, employees[i].department, employees[i].salary, employees[i].bonus, employees[i].taxes);
    }
    printf("\n");
    for (i = 0; i < k; i++) {
        if (employees[i].department == lowest_salary_department && employees[i].salary + employees[i].bonus - employees[i].taxes == lowest_salary) {
            printf("%s %s\n", employees[i].surname, employees[i].name);
            break;
        }
    }
    printf("\n");
    for (i = 0; i < k; i++) {
        if (employees[i].department == highest_salary_department && employees[i].salary + employees[i].bonus - employees[i].taxes == highest_salary) {
            printf("%s %s\n", employees[i].surname, employees[i].name);
            break;
        }
    }

    return 0;
}