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
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Функция для заполнения массива случайными числами из диапазона [a, b]
void random_array(int *arr, int n, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = a + rand() % (b - a + 1);
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

    int *temp = (int *)malloc(m * sizeof(int));
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
  
    free(temp);
}

// Функция для сохранения массива в текстовый файл
void save_array(int *arr, int n, char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Невозможно открыть файл %s\n", filename);
        return;
    }

    // Запись размера массива в первую строку файла
    fprintf(f, "%d\n", n);

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", arr[i]);
    }

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

    *arr = (int *)realloc(*arr, *n * sizeof(int));
}

// Функция для добавления нескольких элементов в указанное место (со сдвигом)
void insert_array(int **arr, int *n, int pos, int count) {
    if (pos < 0 || pos > *n || count < 0) {
        printf("Невозможно выполнить добавление: некорректные параметры\n");
        return;
    }
  
    *n += count;

    *arr = (int *)realloc(*arr, *n * sizeof(int));

    for (int i = *n - 1; i >= pos + count; i--) {
        (*arr)[i] = (*arr)[i - count];
    }

    // Заполнение добавленных элементов случайными числами из диапазона [10; 15]
    random_array(*arr + pos, count, 10, 15);
}

// Функция для подсчета количества присваиваний и сравнений при сортировке массива по неубыванию методом выбора (выделения)
void count_selection_sort(int *arr, int n, int *assigns, int *compares) {
    *assigns = 0;
    *compares = 0;

    // Перебор всех элементов массива, кроме последнего
    for (int i = 0; i < n - 1; i++) {
        // Поиск минимального элемента в подмассиве arr[i..n-1]
        int min = i; // индекс минимального элемента
        (*assigns)++; // увеличение счетчика присваиваний на 1
        for (int j = i + 1; j < n; j++) {
            (*compares)++; // увеличение счетчика сравнений на 1
            if (arr[j] < arr[min]) {
                min = j; // обновление индекса минимального элемента
                (*assigns)++; // увеличение счетчика присваиваний на 1
            }
        }
        // Обмен местами arr[i] и arr[min], если они различны
        (*compares)++; // увеличение счетчика сравнений на 1
        if (i != min) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            (*assigns) += 3; // увеличение счетчика присваиваний на 3
        }
    }
}

// Функция для подсчета количества присваиваний и сравнений при модифицированной сортировке массива по неубыванию методом выбора (выделения)
void count_improved_selection_sort(int *arr, int n, int *assigns, int *compares) {
    *assigns = 0;
    *compares = 0;

    // Перебор всех элементов массива, кроме последнего
    for (int i = 0; i < n - 1; i++) {
        // Поиск минимального и максимального элементов в подмассиве arr[i..n-1-i]
        int min = i; // индекс минимального элемента
        int max = n - 1 - i; // индекс максимального элемента
        (*assigns) += 2; // увеличение счетчика присваиваний на 2
        for (int j = i + 1; j < n - i; j++) {
            (*compares) += 2; // увеличение счетчика сравнений на 2
            if (arr[j] < arr[min]) {
                min = j; // обновление индекса минимального элемента
                (*assigns)++; // увеличение счетчика присваиваний на 1
            }
            if (arr[j] > arr[max]) {
                max = j; // обновление индекса максимального элемента
                (*assigns)++; // увеличение счетчика присваиваний на 1
            }
        }
        // Обмен местами arr[i] и arr[min], если они различны
        (*compares)++; // увеличение счетчика сравнений на 1
        if (i != min) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            (*assigns) += 3; // увеличение счетчика присваиваний на 3
        }
        // Обмен местами arr[n-1-i] и arr[max], если они различны и не совпадают с arr[i]
        (*compares) += 2; // увеличение счетчика сравнений на 2
        if (n - 1 - i != max && max != i) {
            int temp = arr[n - 1 - i];
            arr[n - 1 - i] = arr[max];
            arr[max] = temp;
            (*assigns) += 3; // увеличение счетчика присваиваний на 3
        }
    }
}

int main() {
    int n = 20;
    //int m;
    int *arr = (int *)malloc(n * sizeof(int));
    //scanf("%d", &m);
    // Заполнение массива случайными числами из диапазона [10; 15]
    random_array(arr, n, 10, 15);

    // Вывод массива на экран
    print_array(arr, n);

    // Сортировка массива по неубыванию методом выбора
    int assigns, compares;
    count_selection_sort(arr, n, &assigns, &compares);
    printf("Присваиваний: %d\n", assigns);
    printf("Сравнений при сортировке: %d\n", compares);

    // Сортировке массива по неубыванию методом выбора модивифицированный
    count_improved_selection_sort(arr, n, &assigns, &compares);
    printf("Присваиваний модифицированной: %d\n", assigns);
    printf("Сравнений модифицированной: %d\n", compares);

    // Вывод массива на экран
    print_array(arr, n);

  
    printf("\n");

    return 0;
}
  