#include <stdio.h>
#include <stdlib.h>


struct Date{

    int day;
    int month;
    int year;
};

void int_demo(void);
void double_demo(void);
void date_demo(void);

int main(void)
{
    int_demo();
    double_demo();
    date_demo();

    return 0;
}

void int_demo(void)
{
    int* p = NULL;
    int val;

    p = (int*)malloc(sizeof(int));            // 4 bytes (int) allocated in heap 
    //typecast with int

    if(NULL == p)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    // Read / write as many times as you want
    *p = 10;
    val = *p;
    printf("val = %d\n",val);

    free(p);

    p = NULL;
}

void double_demo(void)
{
    double *p = NULL;
    double val;

    p = (double*)malloc(sizeof(double));

    if(NULL == p)
    {
        puts("ERROR IN ALLOCATING MEMORY");
        exit(-1);
    }

    *p = 4.5;
    val = *p;
    printf("val = %f\n" , val);

    free(p);

    p = NULL;
}

void date_demo(void)
{
    struct Date* pDate = NULL;
    int day,month,year;

    pDate = (struct Date*)malloc(sizeof(struct Date));
    if(NULL == pDate)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    pDate->day = 15;
    pDate->month = 10;
    pDate->year = 2025;

    printf("Date : %d/%d/%d\n", pDate->day , pDate->month , pDate->year);

    free(pDate);

    pDate = NULL;
}


// void* malloc(size_t);

//int n;      //int is type annotation

//int my_add(int,int);

