#include<stdio.h>

#define MAX 5

struct stack
{
    int array [MAX];
    int top;
};

void push(struct stack *s, int item);
int *pop(struct stack *s);
void init_stack(struct stack *s);

int main(void)
{
    struct stack s;
    init_stack(&s);

    push(&s, 11);
    push(&s, 12);
    push(&s, 13);
    push(&s, 14);
    push(&s, 15);
    push(&s, 16);
    push(&s, 17);

    int *i = NULL;

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }

    i = pop(&s);
    if(i) { printf (" Item popped : %d\n", * i); }


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

