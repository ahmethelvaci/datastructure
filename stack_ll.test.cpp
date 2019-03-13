#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int main() 
{
    printf("%d - %d - %d - %d", 0%2, 1%2, 2%2, 3%2);
    return 0;
    node * s1;
    node * s2;
    s1 = init();
    s2 = init();

    for(int i = 0; i < 100; i++)
    {
        push(s1, (i+1)*2);
    }
    dump(s1);
    for(int i = 0; i < 101; i++)
    {
        push(s2, pop(s1));
    }
    dump(s2);
    dump(s1);

}
//https://www.youtube.com/watch?v=qMG5LvPoTis&list=PLh9ECzBB8tJN9bckI6FbWB03HkmogKrFT&index=9