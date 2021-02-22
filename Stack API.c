#include<stdio.h>

#define MAX 5

struct stack
{
    int array [MAX];
    int top;
};

int main(void)
{
    struct stack s;
    init
}

void init_stack(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int item)
{
    if(s->top == MAX -1)
    {
        printf(" Stack is full . Couldn ’t push ’%d’ onto stack \n", item);
        return;
    }
    s->top++;
    s->array [s->top] = item;
}

int *pop(struct stack *s)
{
    int *data;
    if(s->top == -1)
    {
        printf (" Stack is empty \n");
        return NULL;
    }
    data = &s->array[s->top];

    s->top--;

    return data;
}

