#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для обнуления элементов массива
void zero_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

// Функция для заполнения массива значениями с клавиатуры
void input_array(int *arr, int n) {
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Функция для заполнения массива случайными числами из диапазона [a, b]
void random_array(int *arr, int n, int a, int b) {
    srand(time(NULL)); // инициализация генератора случайных чисел
    for (int i = 0; i < n; i++) {
        arr[i] = a + rand() % (b - a + 1); // генерация случайного числа из [a, b]
    }
}

// Функция для вывода массива на экран
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для определения суммы элементов массива
int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}


// Функция для перестановки первых 2n элементов массива по заданному правилу
void swap_array(int *arr, int n, int m) {
    // Проверка на достаточность размера массива
    if (m * 2 > n) {
        printf("Невозможно выполнить перестановку: размер массива меньше 2n\n");
        return;
    }

    // Создание временного массива для хранения первых n элементов
    int *temp = (int *)malloc(m * sizeof(int));

    // Копирование первых m элементов во временный массив
    for (int i = 0; i < m; i++) {
        temp[i] = arr[i];
    }

    // Сдвиг вторых m элементов в начало массива
    for (int i = 0; i < m; i++) {
        arr[i] = arr[m + i];
    }

    // Копирование временного массива в конец исходного массива в обратном порядке
    for (int i = 0; i < m; i++) {
        arr[m + i] = temp[m - 1 - i];
    }

    // Освобождение памяти, выделенной под временный массив
    free(temp);
}

// Функция для сохранения массива в текстовый файл
void save_array(int *arr, int n, char *filename) {
    // Открытие файла для записи
    FILE *f = fopen(filename, "w");

    // Проверка на успешность открытия файла
    if (f == NULL) {
        printf("Невозможно открыть файл %s\n", filename);
        return;
    }

    // Запись размера массива в первую строку файла
    fprintf(f, "%d\n", n);

    // Запись элементов массива во вторую строку файла через пробел
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", arr[i]);
    }

    // Закрытие файла
    fclose(f);
}

// Функция для чтения массива из текстового файла
int *read_array(char *filename, int *n) {
    // Открытие файла для чтения
    FILE *f = fopen(filename, "r");

    // Проверка на успешность открытия файла
    if (f == NULL) {
        printf("Невозможно открыть файл %s\n", filename);
        return NULL;
    }

    // Чтение размера массива из первой строки файла
    fscanf(f, "%d", n);

    // Выделение памяти под массив
    int *arr = (int *)malloc(*n * sizeof(int));

    // Чтение элементов массива из второй строки файла
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d", &arr[i]);
    }

    // Закрытие файла
    fclose(f);

    // Возврат указателя на массив
    return arr;
}

// Функция для удаления нескольких элементов из указанного места (со сдвигом)
void delete_array(int **arr, int *n, int pos, int count) {
    // Проверка на корректность позиции и количества удаляемых элементов
    if (pos < 0 || pos >= *n || count < 0 || count > *n - pos) {
        printf("Невозможно выполнить удаление: некорректные параметры\n");
        return;
    }

    // Сдвиг оставшихся элементов влево на count позиций
    for (int i = pos; i < *n - count; i++) {
        (*arr)[i] = (*arr)[i + count];
    }

    // Уменьшение размера массива на count
    *n -= count;

    // Изменение размера занимаемого массивом блока памяти
    *arr = (int *)realloc(*arr, *n * sizeof(int));
}

// Функция для добавления нескольких элементов в указанное место (со сдвигом)
void insert_array(int **arr, int *n, int pos, int count) {
    // Проверка на корректность позиции и количества добавляемых элементов
    if (pos < 0 || pos > *n || count < 0) {
        printf("Невозможно выполнить добавление: некорректные параметры\n");
        return;
    }

    // Увеличение размера массива на count
    *n += count;

    // Изменение размера занимаемого массивом блока памяти
    *arr = (int *)realloc(*arr, *n * sizeof(int));

    // Сдвиг оставшихся элементов вправо на count позиций
    for (int i = *n - 1; i >= pos + count; i--) {
        (*arr)[i] = (*arr)[i - count];
    }

    // Заполнение добавленных элементов случайными числами из диапазона [10; 15]
    random_array(*arr + pos, count, 10, 15);
}

// Главная функция программы
int main() {
    int n = 20;
    int m;
    int *arr = (int *)malloc(n * sizeof(int));
    scanf("%d", &m);
    // Заполнение массива случайными числами из диапазона [10; 15]
    random_array(arr, n, 10, 15);

    // Вывод массива на экран
    print_array(arr, n);

    // Вызов функции для перестановки
    swap_array(arr, n, m);
  
    // Вывод массива на экран после перестановки
    print_array(arr, n);

    printf("\n");

    return 0;
}
  