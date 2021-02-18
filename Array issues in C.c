#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i , n = 3, d;

    ptr = (int*) malloc(n * sizeof(int));

    printf("Enter elements: ");
    for(i = 0; i < n; ++i)
    {
        if (i+1 == n)
        {
            n=n*n;
            ptr = realloc(ptr, n * sizeof(int));
        }
        scanf_s("%d", ptr + i);
        if ((ptr[i]) == 1)
        {
            goto end;
        }
        n++;

        if(ptr == NULL)
        {
            printf("Error! memory not allocated.");
            exit(0);
        }
    }

    end:
    //here I learned that I can not find out how many elements are in the array
    //It is just showing how big is the array... another plus for Python!
    //length = sizeof(ptr)/sizeof(ptr[0]);
    //length = sizeof(ptr);
    for(d = 0; d < i; d++)
        printf("%d ", ptr[d]);
    free(ptr);

    return 0;
}
