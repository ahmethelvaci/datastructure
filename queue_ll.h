#ifndef queue_ll
#define queue_ll

struct n {
    unsigned int data;
    n *next;
};

typedef n node;

struct q {
    node *head;
    node *tail;
};

typedef q queue;

queue * createQueue();
void enque(queue *, unsigned int);
unsigned int deque(queue *);

#endif // queue_ll
