#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int key;
    struct Node* next;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void addLast(struct Node** head, int key) {
    struct Node* newNode = createNode(key);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addFirst(struct Node** head, int key) {
    struct Node* newNode = createNode(key);
    newNode->next = *head;
    *head = newNode;
}

void addAfter(struct Node* head, int u, int v) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->key == v) {
            struct Node* newNode = createNode(u);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void addBefore(struct Node** head, int u, int v) {
    struct Node* temp = *head;
    if (temp->key == v) {
        addFirst(head, u);
        return;
    }
    while (temp->next != NULL) {
        if (temp->next->key == v) {
            struct Node* newNode = createNode(u);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void removeNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->key == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printList(struct Node* node, FILE* outputFile) {
    while (node != NULL) {
        fprintf(outputFile, "%d ", node->key);
        node = node->next;
    }
}

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Không thể mở file đầu vào.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Không thể mở file đầu ra.\n");
        return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int key;
        fscanf(inputFile, "%d", &key);
        addLast(&head, key);
    }

    char command[20];
    int k, u, v;

    while (1) {
        fscanf(inputFile, "%s", command);
        if (command[0] == '#') {
            break;
        } else if (strcmp(command, "addlast") == 0) {
            fscanf(inputFile, "%d", &k);
            addLast(&head, k);
        } else if (strcmp(command, "addfirst") == 0) {
            fscanf(inputFile, "%d", &k);
            addFirst(&head, k);
        } else if (strcmp(command, "addafter") == 0) {
            fscanf(inputFile, "%d %d", &u, &v);
            addAfter(head, u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            fscanf(inputFile, "%d %d", &u, &v);
            addBefore(&head, u, v);
        } else if (strcmp(command, "remove") == 0) {
            fscanf(inputFile, "%d", &k);
            removeNode(&head, k);
        } else if (strcmp(command, "reverse") == 0) {
            reverseList(&head);
        }
    }

    printList(head, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}