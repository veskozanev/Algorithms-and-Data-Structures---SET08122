#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6

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
    struct stack one;
    struct stack two;
    struct stack three;
    struct stack four;
    struct stack five;
    struct stack six;
    struct stack seven;
    init_stack(&one);
    init_stack(&two);
    init_stack(&three);
    init_stack(&four);
    init_stack(&five);
    init_stack(&six);
    init_stack(&seven);

    int user = 0;
    int user_input_row;
    int n, mod;

    for (user; user < MAX; user++)
    {
        printf("User %d turn. Enter a row:", user % 2);
        scanf("%d", &user_input_row);
        push(&one, user % 2);

        for (int i = 0; i < MAX; i++)
        printf("[ %d ]\n", one.array[i]);
    }

}

void init_stack(struct stack *s)
{
    s->top = -1;
    for (int i = 0; i < MAX; i++) {
        s->array[i] = 8;
    }
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

