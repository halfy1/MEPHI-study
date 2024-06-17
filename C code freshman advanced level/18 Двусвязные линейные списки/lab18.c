#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

// Функция поиска элемента в списке
Node *search(Node *head, int value) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Функция добавления нового элемента после заданного
void insertAfter(Node *node, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = node->next;
    newNode->prev = node;
    if (node->next != NULL) {
        node->next->prev = newNode;
    }
    node->next = newNode;
}

// Функция удаления элемента из списка
void deleteNode(Node **head, Node *node) {
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    free(node);
}

// Функция вывода списка на экран
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%4d ", current->data);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    
    while (1) {
        int value;
        if (scanf("%d", &value) == 1) { // Проверяем, что введено число
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = value;
            newNode->next = NULL;
            
            if (head == NULL) {
                head = newNode;
                tail = newNode;
                newNode->prev = NULL;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } else {
            char c;
            scanf("%c", &c);
            if (c == 'n') { // Проверяем, что это символ 'n'
                break;
            }
        }
        
        char c; // Пропускаем пробелы и другие символы между числами
        while ((c = getchar()) != EOF && c != ' ');
        
        ungetc(c, stdin); // Возвращаем последний символ обратно в поток ввода
    }

    // Поиск элемента
    int searchValue;
    scanf("%d", &searchValue);
    
    Node *foundNode = search(head, searchValue);
    
    if (foundNode != NULL) {
        // Добавление новых элементов из строки, введенной пользователем       
        while (1) {
            int newValue;
            if (scanf("%d", &newValue) == 1) { // Проверяем, что введено число
                insertAfter(foundNode, newValue);
                foundNode = foundNode->next; // Добавляем после последнего добавленного элемента
            } else { // Если введено не число
                char c;
                scanf("%c", &c);
                if (c == 'n') {
                    break; 
                }
            }
            
            char c; // Пропускаем пробелы и другие символы между числами
            while ((c = getchar()) != EOF && c != ' ');
            
            ungetc(c, stdin); // Возвращаем последний символ обратно в поток ввода
        }
        
        printList(head);
        
        // Удаление найденного элемента
        deleteNode(&head, foundNode);
        
        printf("\n");
        printList(head);
        
    } else {
        printList(head);
    }

}
