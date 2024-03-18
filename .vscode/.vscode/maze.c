#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int row, col;
    int step;
    struct Node *parent;
} Node;

int A[MAX][MAX];
int n, m;
int r0, c0, r1, c1;
int visit[MAX][MAX];

typedef struct QueueNode {
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Node *node) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = node;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node *dequeue(Queue *q) {
    if (isEmpty(q)) {
        return NULL;
    }

    QueueNode *temp = q->front;
    Node *data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int legal(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m && A[r][c] == 0 && visit[r][c] == 0;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &r0, &c0, &r1, &c1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
            visit[i][j] = 0;
        }
    }

    Queue q;
    initQueue(&q);

    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->row = r0;
    startNode->col = c0;
    startNode->step = 0;
    startNode->parent = NULL;

    enqueue(&q, startNode);
    visit[r0][c0] = 1;

    Node *finalNode = NULL;

    while (!isEmpty(&q)) {
        Node *node = dequeue(&q);

        if (node->row == r1 && node->col == c1) {
            finalNode = node;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int nr = node->row + nr[k];
            int nc = node->col + nc[k];

            if (legal(nr, nc)) {
                visit[nr][nc] = 1;
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->row = nr;
                newNode->col = nc;
                newNode->step = node->step + 1;
                newNode->parent = node;

                enqueue(&q, newNode);
            }
        }
    }

    int dem = -1;
    while (finalNode != NULL) {
        finalNode = finalNode->parent;
        dem++;
    }

    printf("%d", dem);

    return 0;
}
