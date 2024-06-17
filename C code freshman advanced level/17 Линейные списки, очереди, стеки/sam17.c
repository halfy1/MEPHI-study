#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла списка
typedef struct node {
    int data;
    struct node *next;
} Node;

// Функция для добавления элемента в начало списка
void add_to_start(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node)); // Выделение памяти для нового узла
    new_node->data = data; // Присваивание данных новому узлу
    new_node->next = *head; // Связывание нового узла с головным узлом списка
    *head = new_node; // Обновление указателя на головной узел списка
}

// Функция для добавления элемента в конец списка
void add_to_end(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node)); // Выделение памяти для нового узла
    new_node->data = data; // Присваивание данных новому узлу
    new_node->next = NULL; // Инициализация указателя на следующий узел как NULL

    if (*head == NULL) { // Если список пустой
        *head = new_node; // Обновление указателя на головной узел списка
        return;
    }

    Node *current = *head; // Инициализация указателя на текущий узел как головной узел списка
    while (current->next != NULL) { // Пока следующий узел не NULL, выполнять цикл
        current = current->next; // Переход к следующему узлу в списке
    }
    current->next = new_node; // Связывание последнего узла списка с новым узлом
}

// Функция для удаления элемента из начала списка
int remove_from_start(Node **head) {
    if (*head == NULL) { // Проверка на пустоту списка
        printf("Список пуст\n");
        return -1;
    }
    Node *temp = *head;
    int data = temp->data;
    *head = temp->next; // Обновление указателя на головной узел списка
    free(temp); // Освобождение памяти от удаленного узла
    return data; // Возвращение данных удаленного узла
}

// Функция для удаления элемента из конца списка
int remove_from_end(Node **head) {
    if (*head == NULL) { // Проверка на пустоту списка
        printf("Список пуст\n");
        return -1;
    }
    if ((*head)->next == NULL) { // Если в списке только один элемент
        int data = (*head)->data; // Сохранение данных головного узла в переменную data
        free(*head); // Освобождение памяти от удаленного узла
        *head = NULL; // Обновление указателя на головной узел списка как NULL (список теперь пустой)
        return data; // Возвращение данных удаленного узла
    }
    Node *current = *head; // Инициализация указателя на текущий узел как головной узел списка
    while (current->next->next != NULL) { // Пока следующий за следующим узел не NULL, выполнять цикл
        current = current->next; // Переход к следующему узлу в списке
    }
    int data = current->next->data; // Сохранение данных последнего узла в переменную data
    free(current->next); // Освобождение памяти от удаленного узла
    current->next = NULL; // Обновление указателя на следующий узел предпоследнего узла списка как NULL
    return data; // Возвращение данных удаленного узла
}

// Функция для вывода всех элементов списка на экран (от начального до конечного)
void print_list(Node *head) {
    Node *current = head; // Инициализация указателя на текущий узел как головной узел списка
    while (current != NULL) { // Пока текущий узел не NULL, выполнять цикл
        printf("%4d ", current->data); // Вывод данных текущего узла на экран
        current = current->next; // Переход к следующему узлу в списке
    }
}

// Функция для поиска в списке элемента с заданным значением
Node* find_element(Node *head, int value) {
  Node* current=head; // Инициализация указателя на текущий узел как головной узел списка

  while(current!=NULL){ // Пока текущий узел не NULL, выполнять цикл
      if(current->data==value){ // Если данные текущего узла равны заданному значению
          return current;  // Возвращение указателя на найденный узел
      }
      current=current->next;
  }
  return NULL;
}

// Функция для удаления из списка элемента, следующего после элемента, адрес которого известен
void remove_next_element(Node* element){
  if(element==NULL || element->next==NULL){ // Если элемент равен NULL или следующий за ним элемент равен NULL
      return;  // Завершение функции (ничего не делаем)
  }

  Node* temp=element->next;  // Сохранение указателя на следующий за данным элементом во временную переменную
  element->next=temp->next;  // Обновление указателя на следующий за данным элементом
  free(temp);  // Освобождение памяти от удаленного узла
}

// Функция для заполнения списка данными, введенными пользователем с клавиатуры в одну строку до появления буквы 'n'
void fill_list(Node **head) {
    int data;
    while (scanf("%d", &data) == 1) { // Пока успешно считывается число с клавиатуры, выполнять цикл
        add_to_end(head, data); // Добавление считанного числа в конец списка
    }
}

int main() {
    Node *head = NULL; // Инициализация указателя на головной узел списка как NULL (список пустой)

    fill_list(&head);

  // Очистка входного потока
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    int value;
    scanf("%d", &value);

    Node *found = find_element(head, value);

    if (found != NULL) {
        remove_next_element(found); 
    }

    print_list(head);

    return 0;
}
