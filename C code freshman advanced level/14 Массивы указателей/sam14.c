#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для обмена двумя указателями на строки
void swap_pointers(char **p1, char **p2) {
    char *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Функция для сортировки массива указателей на строки по алфавиту
void sort_pointers(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcasecmp(arr[i], arr[j]) > 0) { //strcasecmp для сравнения без учета регистра
                swap_pointers(&arr[i], &arr[j]);
            }
        }
    }
}

// Функция для вывода массива указателей на строки на экран
void print_pointers(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

// Функция для заполнения массива символов вводимыми с клавиатуры
void input_data(char *buffer, char **pointers, int n) {
    printf("Введите %d слов(а), разделяя их пробелами:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        pointers[i] = buffer; 
        buffer += strlen(buffer) + 1;
    }
}

// Функция для заполнения массива символов и массива указателей на строки значениями из текстового файла
void read_data(char *buffer, char **pointers, int n, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fgets(buffer, 256, file);
        buffer[strcspn(buffer, "\n")] = '\0'; // удаляем символ перевода строки из буфера
        pointers[i] = buffer; // сохраняем указатель на начало строки
        buffer += strlen(buffer) + 1; // переходим к следующему свободному месту в буфере
    }
    fclose(file);
}

// Функция для разделения списка на 3 части
void divide_participants(char **pointers, int n) {
    int count[26] = {0}; // массив для подсчета количества фамилий, начинающихся с каждой буквы алфавита
    for (int i = 0; i < n; i++) {
        char first_letter = toupper(pointers[i][0]);
        count[first_letter - 'A']++;
    }
    int total = 0; // общее количество участников
    for (int i = 0; i < 26; i++) { // для каждой буквы алфавита
        total += count[i]; // добавляем количество участников, фамилии которых начинаются с этой буквы
    }
    int target = total / 3; // целевое количество участников в каждой части
    int part1 = 0, part2 = 0, part3 = 0; // текущее количество участников в каждой части
    int index1 = 0, index2 = 0, index3 = 0; // индексы букв, которые являются границами частей
    for (int i = 0; i < 26; i++) { // для каждой буквы алфавита
        if (part1 < target) { // если первая часть еще не достигла цели
            part1 += count[i]; // добавляем к ней количество участников с этой буквой
            index1 = i; // запоминаем индекс буквы как границу первой части
        } else if (part2 < target) { // если вторая часть еще не достигла цели
            part2 += count[i]; // добавляем к ней количество участников с этой буквой
            index2 = i; // запоминаем индекс буквы как границу второй части
        } else { // иначе
            part3 += count[i]; // добавляем к третьей части количество участников с этой буквой
            index3 = i; // запоминаем индекс буквы как границу третьей части
        }
    }
  
    // Выводим на экран интервалы первых букв фамилий и количество участников в каждой части
    printf("A-%c %d\n", 'A' + index1, part1);
    printf("%c-%c %d\n", 'A' + index1 + 1, 'A' + index2, part2);
    printf("%c-Z %d\n", 'A' + index2 + 1, part3);
}

int main() {
    int n = 10;
    char buffer[256 * n]; 
    char *pointers[n];
    
    input_data(buffer, pointers, n);

  
    sort_pointers(pointers, n); // сортируем список слов по алфавиту
    print_pointers(pointers, n); // выводим отсортированный список слов на экран
    printf("\n");
    divide_participants(pointers, n); // разделяем список фамилий участников конференции на три приблизительно равные части по первой букве
    
    return 0;
}
