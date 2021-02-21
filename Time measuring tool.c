#include<time.h>
#include<stdio.h>
#include <stdlib.h>

void code()
{
    for(int i=0; i<10000; i++)
    {
        printf(".");
    }
    printf("\n") ;
}

int main()
{
    double sum = 0;
    //double sum1 = 0;
    int n;
    char fileName [50];
    double *ptr;
    FILE *fpt;


    printf("Enter number of elements: ");
    scanf_s("%d", &n);
    printf("Enter file name: ");
    scanf_s("%s", &fileName);
    fpt = fopen(fileName, "w+");
    fprintf(fpt,"Running time:\n");




    ptr = (double*) calloc(n, sizeof(double));
    if(ptr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    for(int i=0; i < n; i++)
    {
        clock_t t;
        t=clock();
        code();
        t=clock()-t;
        ptr[i]=(double) t/CLOCKS_PER_SEC;
        sum += (double) t/CLOCKS_PER_SEC;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fpt,"%lf\n", (double) ptr[i]);
        //printf("%lf, ", (double) ptr[i]);
        //sum1 += (double) ptr[i];
    }
    fprintf(fpt,"\n\n Elapsed Average: %f seconds: ",sum/n);
    //printf(" Elapsed Average: %f seconds \n",sum/n);
    //printf(" Elapsed Average: %f seconds \n",sum1/n);
    free(ptr);
    fclose(fpt);
    return 0;
}