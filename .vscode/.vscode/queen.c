#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->right);
        printf("%c ", root->key);
        printInOrder(root->left);
    }
}

int isTreeEmpty(Node* root) {
    return root == NULL;
}

int main() {
    Node* root = NULL;
    char operation, key;

    while (1) {
        scanf(" %c", &operation);

        if (operation == 'insert') {
            scanf(" %c", &key);
            root = insert(root, key);
        } else  
            if (operation == ' del') {
            scanf(" %c", &key);
            root = deleteNode(root, key);
    }
 if (!isTreeEmpty(root)) {
                printInOrder(root);
            } else {
                printf("NULL");
            }
    return 0;
}
}