#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void int_demo(void);
void float_demo(void);
void date_demo(void);


int main(void)
{
    int_demo();

    return 0;
}

void int_demo(void)
{
    int *p = NULL;
    p = (int*)malloc(sizeof(int));
    
    if(p==NULL)
    {
        pputs("Error in allocating memory");
        exit(-1);
    }

    *p = 100;
    printf("p = %d\n", *p);

    free(p);
    p = NULL;

    *p = 20;
    printf("p = %d Again access\n", *p);
}