#ifndef queue_arr
#define queue_arr
struct q
{
    unsigned int length;
    unsigned int head;
    unsigned int tail;
    unsigned int * arr;   
};
typedef q queue;
queue * init();
int deque(queue *);
void enque(queue *, unsigned int);
void dump(queue *);
#endif // queue_arr
