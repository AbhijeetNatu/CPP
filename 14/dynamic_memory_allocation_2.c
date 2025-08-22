#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void int_arr_demo(void);
void float_arr_demo(void);
void date_arr_demo(void);

int main(void)
{
    int_arr_demo();
    float_arr_demo();
    date_arr_demo();

    return 0;
}

void int_arr_demo(void)
{
    int* a = NULL;
    int a_size = 5;
    int i;
    int val;
    puts("***** INT ARR DEMO *****");

    a = (int*)malloc(a_size * sizeof(int));

    if (a == NULL)  
    {
        puts("ERROR");
        exit(-1);
    }

    for (i = 0; i < a_size; ++i)
    {
        *(a + i) = (i + 1) * 100;
    }

    for (i = 0; i < a_size; ++i)  
    {
        val = a[i];
        printf("a[%d]: %d\n", i, val);
    }

    free(a);
    a = NULL;
}

void float_arr_demo(void)
{
    float* a = NULL;
    int a_size = 5;  
    int i;
    float val;  

    puts("***** FLOAT ARR DEMO *****");
    a = (float*)malloc(a_size * sizeof(float));

    if (a == NULL)  
    {
        puts("ERROR");
        exit(-1);
    }

    for (i = 0; i < a_size; ++i)
    {
        *(a + i) = (i + 1) * 10.5;
    }

    for (i = 0; i < a_size; ++i)  
    {
        val = a[i];
        printf("a[%d]: %.2f\n", i, val);  
    }

    free(a);
    a = NULL;
}

void date_arr_demo(void)
{
    struct Date* pDate_arr = NULL;
    int a_size = 5;
    int i;

    puts("***** Date ARR DEMO *****");
    pDate_arr = (struct Date*)malloc(a_size * sizeof(struct Date));
    if (pDate_arr == NULL)  
    {
        puts("ERROR");
        exit(-1);
    }

    for (i = 0; i < a_size; i++)  
    {
        pDate_arr[i].day = i + 2;
        pDate_arr[i].month = 7 - i;
        pDate_arr[i].year = 2025;
    }

    for (i = 0; i < a_size; ++i)  
    {
        printf("Date object at index %d : %d : %d : %d\n",
               i,
               pDate_arr[i].day, pDate_arr[i].month, pDate_arr[i].year);
    }

    free(pDate_arr);
    pDate_arr = NULL;
}
