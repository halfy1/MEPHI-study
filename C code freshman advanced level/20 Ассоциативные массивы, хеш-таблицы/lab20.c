#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 17

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node **table;
    int size;
} HashTable;

// Хеш-функция для вычисления индекса для заданного ключа
int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

// Функция для создания новой хеш-таблицы
HashTable *create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    table->size = TABLE_SIZE;
    table->table = calloc(TABLE_SIZE, sizeof(Node *));
    return table;
}

// Функция для вставки данных в хеш-таблицу
void insert(HashTable *table, int data) {
    int index = hash(data);
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

// Функция для поиска данных в хеш-таблице
int search(HashTable *table, int data) {
    int index = hash(data);
    Node *current = table->table[index];
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Функция для нахождения длины самой длинной цепочки в хеш-таблице
int longest_chain(HashTable *table) {
    int max_length = 0;
    for (int i = 0; i < table->size; i++) {
        int length = 0;
        Node *current = table->table[i];
        while (current != NULL) {
            length++;
            current = current->next;
        }
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}

// Функция для вычисления коэффициента заполнения хеш-таблицы
float load_factor(HashTable *table) {
    int count = 0;
    for (int i = 0; i < table->size; i++) {
        Node *current = table->table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return (float)count / table->size;
}

// Функция для освобождения памяти, выделенной под хеш-таблицу
void free_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Node *current = table->table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->table);
    free(table);
}

int main() {
    HashTable *table = create_table();
    
    printf("Введите 15 чисел: ");
    for (int i = 0; i < 15; i++) {
        int data;
        scanf("%d", &data);
        insert(table, data);
    }
    
    printf("Введите число для поиска: ");
    int data;
    scanf("%d", &data);
    
    if (search(table, data)) {
        printf("Число найдено\n");
    } else {
        printf("Число не найдено\n");
    }
    
    printf("%d\n", longest_chain(table));
    
    printf("%1.2f\n", load_factor(table));
    
    free_table(table);
    
    return 0;
}
