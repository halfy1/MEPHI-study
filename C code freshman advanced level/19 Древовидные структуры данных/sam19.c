#include <stdio.h>
#include <stdlib.h>

// Определение структуры узла дерева
typedef struct node {
    int data; // Данные узла (целое число)
    struct node *left; // Указатель на левое поддерево
    struct node *right; // Указатель на правое поддерево
} Node;

// Функция для создания нового узла дерева с заданными данными
Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node)); // Выделение памяти для нового узла
    new_node->data = data; // Присваивание данных новому узлу
    new_node->left = NULL; // Инициализация указателя на левое поддерево как NULL
    new_node->right = NULL; // Инициализация указателя на правое поддерево как NULL
    return new_node; // Возвращение указателя на созданный узел
}

// Функция для добавления элемента в двоичное дерево поиска
void insert(Node **root, int data) {
    if (*root == NULL) { // Если дерево пустое
        *root = create_node(data); // Создание нового узла с заданными данными и обновление указателя на корень дерева
        return;
    }
    if (data < (*root)->data) { // Если данные меньше данных корня дерева
        insert(&((*root)->left), data); // Рекурсивный вызов функции для добавления элемента в левое поддерево
    } else { // Если данные больше или равны данным корня дерева
        insert(&((*root)->right), data); // Рекурсивный вызов функции для добавления элемента в правое поддерево
    }
}

// Функция для вывода всех элементов дерева на экран (в порядке обхода "корень-левый-правый")
void print_tree(Node *root) {
    if (root == NULL) { // Если дерево пустое, завершаем функцию (ничего не делаем)
        return;
    }
    printf("%4d ", root->data); // Вывод данных корня дерева на экран
    print_tree(root->left); // Рекурсивный вызов функции для вывода элементов левого поддерева на экран
    print_tree(root->right); // Рекурсивный вызов функции для вывода элементов правого поддерева на экран
}

// Функция для поиска в дереве заданного значения
Node* find_value(Node* root, int value){
  if(root==NULL){ // Если дерево пустое или значение не найдено
      return NULL; 
  }

  if(root->data==value){ // Если данные корня равны искомому значению
      return root; 
  }

  if(value<root->data){ // Если искомое значение меньше данных корня 
      return find_value(root->left,value); 
  }else{ 
      return find_value(root->right,value); 
  }
}

// Функция для поиска минимального значения в дереве (наименьший элемент в правом поддереве)
Node* find_minimum(Node* root){
  while(root->left!=NULL){
      root=root->left; 
  }
  return root; 
}

// Функция для удаления из дерева заданного значения
Node* delete_value(Node* root, int value){
  if(root==NULL){ 
      return root; 
  }

  if(value<root->data){ 
      root->left=delete_value(root->left,value); 
  }else if(value>root->data){ 
      root->right=delete_value(root->right,value); 
  }else{ 

      if(root->left==NULL && root->right==NULL){ 
          free(root); 
          return NULL; 
      }else if(root->left==NULL || root->right==NULL){ 
          Node* temp; 
          if(root->left==NULL){
              temp=root->right; 
          }else{
              temp=root->left; 
          }
          free(root); 
          return temp; 
      }else{ 
          Node* temp=find_minimum(root->right); 
          root->data=temp->data; 
          root->right=delete_value(root->right,temp->data); 
      }
  }
  return root; 
}

// Функция для определения суммы всех терминальных узлов (листьев) дерева
int sum_leaves(Node *root) {
    if (root == NULL) { // Если дерево пустое, возвращаем 0
        return 0;
    }
    if (root->left == NULL && root->right == NULL) { // Если узел является листом (терминальным узлом)
        return root->data; // Возвращаем данные этого узла
    }
    // Рекурсивный вызов функции для левого и правого поддеревьев и возвращение суммы результатов
    return sum_leaves(root->left) + sum_leaves(root->right);
}

// Функция для заполнения дерева данными, введенными пользователем с клавиатуры в одну строку до появления буквы 'n'
void fill_tree(Node **root) {
    int data;
    while (scanf("%d", &data) == 1) { // Пока успешно считывается число с клавиатуры, выполнять цикл
        insert(root, data); // Добавление считанного числа в дерево
    }
}

int main() {
    Node *root = NULL; // Инициализация указателя на корень дерева как NULL (дерево пустое)

    fill_tree(&root); // Заполнение дерева данными, введенными пользователем с клавиатуры

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int value;
    scanf("%d", &value);
  
    print_tree(root);
    printf("\n");
  
    root = delete_value(root, value); // Удаление узла со значением value

    print_tree(root);
    printf("\n");

    int sum = sum_leaves(root); // Определение суммы всех терминальных узлов (листьев) дерева
    printf("%d\n", sum);

    return 0;
}
