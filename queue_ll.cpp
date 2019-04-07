#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

node * createNode(unsigned int data)
{
    node * n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

queue * createQueue()
{
    queue * q = (queue*) malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enque(queue * q, unsigned int data) {
    if(q->head == NULL) {
        node * n = createNode(data);
        q->head = n;
        q->tail = n;
        return;
    }
    node * n = createNode(data);
    q->tail->next = n;
    q->tail = n;
}

unsigned int deque(queue * q) {
    if(q->head == NULL) {
        printf("queue is empty");
        return -1;
    }
    node * n = q->head;
    unsigned int rvalue = q->head->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(n);
    return rvalue;
}

int main() {
    queue * q1;
    unsigned int count = 100000;
    q1 = createQueue();
    for(unsigned int i = 0; i < count; i++)
    {
        enque(q1, i);
    }

    for(unsigned int i = 0; i < count; i++)
    {
        deque(q1);
    }
}
