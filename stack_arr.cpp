#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"
stack * init()
{
    stack *s = (stack *) malloc(sizeof(stack));
    s->top = 0;
    s->length = 2;
    s->arr = NULL;
}
int pop(stack *s)
{
    if(s->top <= 0 || s->arr == NULL) {
        printf("stack is empty");
        return -1;
    }
    if (s->top <= s->length/4) {
        printf("resizing down (%d) %d > %d\n", s->top, s->length, s->length/2);
        int *arr2 = (int *) malloc(sizeof(int) * s->length/2);
        for(int i = 0; i < s->length/2; i++)
        {
            arr2[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = arr2;
        s->length /= 2;
    }
    return s->arr[--s->top];
}

void push(int a, stack *s)
{
    if(s->arr == NULL) {
        s->arr = (int *) malloc(sizeof(int)*s->length);
    }
    if (s->top >= s->length-1) {
        printf("resizing up (%d) %d > %d\n", s->top, s->length,s->length*2);
        int *arr2 = (int *) malloc(sizeof(int)*s->length*2);
        for(int i = 0; i < s->length; i++)
        {
            arr2[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = arr2;
        s->length *= 2;
    }
    s->arr[s->top++] = a;
}

void dump(stack *s)
{
    printf("---DUMP---\n");
    for(int i = 0; i < s->top; i++)
    {
        printf("%d->%d\n", i, s->arr[i]);
    }
    printf("---/DUMP---\n");
    
}
