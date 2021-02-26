#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *link;
};

int count (struct node *list)
{
    int count = 0;
    while(list != NULL)
    {
        list = list->link;
        count++;
    }
    return count;
}

void display (struct node *list)
{
    while(list != NULL)
    {
        printf("%d, ", list->data);
        list = list->link;
    }
    printf("\n");
}

void append(struct node **list, int num)
{
    struct node *temp, *r;
    if(*list == NULL)
    {
        temp = (struct node *) malloc(sizeof (struct node));
        temp -> data = num;
        temp -> link = NULL;
        *list = temp;
    }
    else
    {
        temp = *list;
        while(temp -> link != NULL)
        {
            temp = temp ->link;
        }
        r = (struct node *) malloc(sizeof(struct node));
        r -> data = num;
        r -> link = NULL;
        temp -> link = r;
    }
}


void delete (struct node ** list, int num)
{
    struct node *old, *temp;
    temp = *list;
    while(temp != NULL)
    {
        if(temp -> data == num)
        {
            if(temp == *list)
            {
                *list = temp -> link;
            }
            else
                old -> link = temp -> link;
            free(temp);
            return;
        }
        else
        {
            old = temp;
            temp = temp -> link;
        }
    }
    printf("Element %d not found in the supplied list \n", num);
}
void prepend (struct node ** list, int num)
{
    struct node *temp;
    temp = (struct node *) malloc(sizeof (struct node));
    temp->data = num;
    temp->link = *list;
    *list = temp;
}

void insert_after(struct node *list, int location, int num)
{
    struct node *temp, *r;
    int i;
    temp = list;
    for(i=0; i<location; i++)
    {
        temp = temp->link;
        if(temp == NULL)
        {
            printf("Length of the list is %d but the supplied location is %d \n", i, location);
            return;
        }
    }
    r = (struct node *) malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

void insert_before (struct node ** list, int position, int num)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = num;

    struct node *temp = *list;
    struct node *temptest = *list;
    int counter = 0;
    if (position == 0) {
        prepend(list, num);
        return;
    }
    while(temptest != NULL)
    {
        temptest = temptest->link;
        counter++;
    }
    if (counter<=position)
    {
        printf("\n List has %d elements, you want to insert before location %d \n", counter, position);
        return;
    }
    for(int i=1; i < position; i++) {
        if(temp->link != NULL) {
            temp = temp->link;
        }

    }
    newNode->link = temp->link;
    temp->link = newNode;
}


int main(void)
{
    struct node *list;
    list = NULL;

    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    insert_after(list,2,4);
    display(list);
    insert_before(&list, 3, 3111);
    //insertBefore(&list, 2, 1111);
    display(list);
    //prepend(&list, 0);
    //display(list);
/*
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    append(&list, 14);
    append(&list, 30);
    append(&list, 25);
    append(&list, 42);
    append(&list, 17);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    prepend(&list, 999);
    prepend(&list, 888);
    prepend(&list, 777);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    insert_after(list, 1, 0);
    insert_before(list, 1, 1111);
    insert_before(list, 10, 1111);
    insert_after(list, 2, 1);
    insert_after(list, 5, 99);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    insert_after(list, 99, 10);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    delete(&list, 99);
    delete(&list, 1);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);

    delete(&list, 10);
    printf("No of elements in linked list = %d\n", count(list) );
    display(list);
*/



    return 0;
}