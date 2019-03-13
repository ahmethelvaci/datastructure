#ifndef stack_arr
#define stack_arr
struct s
{
    int length;
    int top;
    int * arr;   
};
typedef s stack;
stack * init();
int pop(stack *);
void push(int, stack *);
void dump(stack *);
#endif // stack_arr
