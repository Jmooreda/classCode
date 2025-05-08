/* Implementing a queue using a singly linked list */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SLNode {
    int number;
    struct SLNode* next;
} SLNode;

typedef struct Queue {
    SLNode *front;
    SLNode *rear;
    size_t len;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->len = 0;
}

void enqueue(Queue* queue, int number) {
    SLNode* node = malloc(sizeof(SLNode));          //create a new node in the heap part of memory
    node->number = number;
    node->next = NULL;
    if (queue->rear) {
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
    queue->len++;
}

int dequeue(Queue* queue) {
    assert(queue->front);
    int number = queue->front->number;
    SLNode* nodeToFree = queue->front;
    queue->front = queue->front->next;
    if (!queue->front) {
        queue->rear = NULL;
    }
    free(nodeToFree);
    queue->len--;
    return number;
}

void freeQueue(Queue* queue) {
    while (queue->front) {
        dequeue(queue);
    }
}

int main() {
    Queue queue;        //stored in the stack frame for main
    initQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("Dequeue: %d\n", dequeue(&queue));
    freeQueue(&queue);
    
    return 0;
}
