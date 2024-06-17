#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop() {
    struct Node* temp;
    if (top == NULL) return;
    temp = top;
    top = top->next;
    free(temp);
}

void display() {
    struct Node* temp;
    if (top == NULL) return;
    temp = top;
    while (temp != NULL) {
        printf("%4d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int sum() {
    struct Node* temp;
    int sum = 0;
    if (top == NULL) return 0;
    temp = top;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int main() {
    int n, x, i;   
    while (scanf("%d", &x) == 1) {
        push(x);
        if (getchar() == 'n') break; // признак окончания ввода
    }

    pop();
    pop();
    display();

    printf("%d\n", sum());

    return 0;
}