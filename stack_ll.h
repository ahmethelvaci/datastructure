#ifndef stack_ll
#define stack_ll

struct n
{
    n * next;
    int data;
};
typedef n node;
node * init();
int pop(node *);
void push(node *, int);
void dump(node *);


#endif