#include <stdio.h>
#include <stdlib.h>
#include "queue_arr.h"
queue * init()
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->head = 0;
    q->tail = 0;
    q->length = 2;
    q->arr = NULL;
    return q;
}
int deque(queue *q)
{
    if(q->tail-q->head == 0 || q->arr == NULL) {
        printf("queue is empty\n");
        return -1;
    }

    unsigned int count = q->tail-q->head;

    if (count <= q->length/4) {
        //printf("resizing down (%d-%d) %d > %d\n", q->head, q->tail, q->length, q->length/2);
        unsigned int *arr2 = (unsigned int *) malloc(sizeof(unsigned int) * q->length/2);
        unsigned int arr2_index = 0;
        unsigned int index;
        for(unsigned int i = q->head; i < q->tail; i++)
        {
            index = i % q->length;
            arr2[arr2_index] = q->arr[index];
            arr2_index++;
        }
        free(q->arr);
        q->arr = arr2;
        q->head = 0;
        q->tail = count;
        q->length /= 2;
    }
    unsigned int index = q->head % q->length;
    unsigned int rvalue = q->arr[index];
    q->head++;
    return rvalue;
}

void enque(queue *q, unsigned int a)
{
    if(q->arr == NULL) {
        q->arr = (unsigned int *) malloc(sizeof(unsigned int)*q->length);
    }

    unsigned int count = q->tail-q->head;

    if (count >= q->length) {
        //printf("resizing up (%d-%d) %d > %d\n", q->head, q->tail, q->length,q->length*2);
        unsigned int *arr2 = (unsigned int *) malloc(sizeof(unsigned int)*q->length*2);
        unsigned int arr2_index = 0;
        unsigned int index;
        for(unsigned int i = q->head; i < q->tail; i++)
        {
            index = i % q->length;
            arr2[arr2_index] = q->arr[index];
            arr2_index++;
        }
        free(q->arr);
        q->arr = arr2;
        q->head = 0;
        q->tail = count;
        q->length *= 2;
    }

    unsigned int index = q->tail % q->length;
    q->arr[index] = a;
    q->tail++;
}

void dump(queue *q)
{
    printf("---DUMP---\n");
    unsigned int index;
    for(unsigned int i = q->head; i < q->tail; i++)
    {
        index = i % q->length;
        printf("%d->%d\n", index, q->arr[index]);
    }
    printf("---/DUMP---\n");
}

int main()
{
    // queue * q1 = init();
    // deque(q1);
    // enque(q1, 1);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);
    // enque(q1, 2);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);
    // enque(q1, 3);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);
    // enque(q1, 4);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);
    // enque(q1, 5);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);
    // enque(q1, 6);
    // dump(q1);
    // printf("deque %i\n", deque(q1));
    // dump(q1);

    // queue * q2 = init();
    // enque(q2, 1);
    // enque(q2, 2);
    // dump(q2);
    // printf("deque %i\n", deque(q2));
    // dump(q2);
    // enque(q2, 3);
    // dump(q2);
    // printf("deque %i\n", deque(q2));
    // dump(q2);
    // enque(q2, 4);
    // dump(q2);
    // printf("deque %i\n", deque(q2));
    // dump(q2);

    // queue * q3 = init();
    // for(unsigned int i = 0; i < 20; i++)
    // {
    //     enque(q3, i);
    //     printf("<-- %i\n", i);
    //     if ((i+1) % 2 == 0){

    //         printf("--> %i\n", deque(q3));
    //     }
    //     // dump(q3);
    // }
    // // dump(q3);


    queue * q4 = init();
    unsigned int total = 100000000;
    for(unsigned int i = 0; i < total; i++)
    {
        enque(q4, i);
    }

    for(unsigned int i = 0; i < total; i++)
    {
        deque(q4);
    }
}
