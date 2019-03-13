#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

node * createNode(int data) {
    node * n = (node *) malloc(sizeof(node));
    n->data = data;
}

node * init()
{
    return createNode(0);
}

int pop(node * n)
{
    if(n->next == NULL) {
        printf("stack is empty\n");
        return -1;
    }
    node * temp = n->next;
    int data = temp->data;
    n->next = temp->next;
    free(temp);
    return data; 
}

void push(node * n, int data)
{
    node * temp = createNode(data);
    temp->next = n->next;
    n->next = temp;
}

void dump(node * n)
{
    printf("---DUMP---\n");
    int i = 0;
    while(n->next != NULL)
    {
        printf("%d->%d\n", i, n->next->data);
        n = n->next;
        i++;
    }
    printf("---/DUMP---\n");
    
}

//https://www.youtube.com/watch?v=qMG5LvPoTis&list=PLh9ECzBB8tJN9bckI6FbWB03HkmogKrFT&index=9