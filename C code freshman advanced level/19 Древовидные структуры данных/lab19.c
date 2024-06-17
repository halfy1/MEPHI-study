#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void add_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
        return;
    }

    struct node* current = root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = new_node;
                break;
            }
            else {
                current = current->left;
            }
        }
        else {
            if (current->right == NULL) {
                current->right = new_node;
                break;
            }
            else {
                current = current->right;
            }
        }
    }
}

void print_inorder(struct node* node) {
    if (node == NULL) return;

    print_inorder(node->left);
    printf("%d ", node->data);
    print_inorder(node->right);
}

void print_preorder(struct node* node) {
    if (node == NULL) return;

    printf("%3d ", node->data);
    print_preorder(node->left);
    print_preorder(node->right);
}

int count_levels(struct node* node) {
    if (node == NULL) return 0;

    int left_levels = count_levels(node->left);
    int right_levels = count_levels(node->right);

    return 1 + ((left_levels > right_levels) ? left_levels : right_levels);
}

int sum_nodes_with_children(struct node* node) {
    if (node == NULL) return 0;

    int sum = 0;

    if (node->left != NULL || node->right != NULL) {
        sum += node->data;
    }

    sum += sum_nodes_with_children(node->left);
    sum += sum_nodes_with_children(node->right);

    return sum;
}

void print_breadth_first() {
    struct node** queue = (struct node**)malloc(sizeof(struct node*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node* current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }

    free(queue);
}

void add_random_nodes(int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        int data = rand() % (b - a + 1) + a;
        add_node(data);
    }
}

void delete_tree(struct node* node) {
    if (node == NULL) return;

    delete_tree(node->left);
    delete_tree(node->right);

    free(node);
}

int main() {
    
     int n, a, b, i, x;

    while (scanf("%d", &x) == 1) {
      add_node(x);
    }
//Дерево в прямом порядке обхода: 
     print_preorder(root);
//Количество уровней дерева: 
     //printf("\n%d", count_levels(root));
//Сумма всех узлов дерева с хотя бы одним потомком: 
     printf("\n%d\n", sum_nodes_with_children(root));
/*
     printf("\nДерево в ширину: ");
     print_breadth_first();

     printf("\n");

     printf("\nВведите количество случайных элементов: ");
     scanf("%d", &n);
  
     printf("\nВведите начало интервала: ");
     scanf("%d", &a);

     printf("Введите конец интервала: ");
     scanf("%d", &b);

     add_random_nodes(n, a, b);

     printf("\nДерево в прямом порядке обхода после добавления случайных элементов: ");
     print_preorder(root);

     delete_tree(root);
*/  
}