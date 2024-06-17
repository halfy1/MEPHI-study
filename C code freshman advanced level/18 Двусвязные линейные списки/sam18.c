#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void add_to_head(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) head->prev = new_node;
    head = new_node;
    if (tail == NULL) tail = new_node;
}

void add_to_tail(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = tail;
    new_node->next = NULL;
    if (tail != NULL) tail->next = new_node;
    tail = new_node;
    if (head == NULL) head = new_node;
}

void remove_from_head() {
    if (head == NULL) return;
    struct node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
}

void remove_from_tail() {
    if (tail == NULL) return;
    struct node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    free(temp);
}

void print_list_forward() {
    struct node* current = head;
    while (current != NULL) {
        printf("%4d", current->data);
        current = current->next;
    }
}

void print_list_backward() {
    struct node* current = tail;
    while (current != NULL) {
        printf("%4d ", current->data);
        current = current->prev;
    }
}

int sum_list() {
    int sum = 0;
    struct node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main() {
    int n, x, i;

    while (scanf("%d", &x) == 1) {
      add_to_tail(x);
    }

    remove_from_head();
    remove_from_head();
    print_list_forward();
    printf("\n%d\n", sum_list());
    return 0;
}