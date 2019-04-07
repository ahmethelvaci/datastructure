#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

int main() {
    queue * q1;
    int count = 100000000;
    q1 = createQueue();
    for(int i = 0; i < count; i++)
    {
        q1->enque(i);
    }

    for(int i = 0; i < count; i++)
    {
        q1->deque();
    }
    
}