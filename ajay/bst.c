#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        struct node* temp = malloc(sizeof(struct node));
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(struct node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}