#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node* head = NULL;

void insert(int val) {
    struct node* new = malloc(sizeof(struct node));
    new->data = val;
    new->prev = new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    struct node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;
}

void display() {
    struct node* temp = head;
    printf("DLL: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();
    return 0;
}