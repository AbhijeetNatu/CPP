#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void arr_of_ptrs_to_int_demo(void);
void arr_of_ptrs_to_date_demo(void);

int main()
{
    arr_of_ptrs_to_int_demo();
    arr_of_ptrs_to_date_demo();

    return 0;
}


void arr_of_ptrs_to_int_demo(void){

    int **pp_arr = NULL;    //for storing address of index 0 of array of pointers to int
    int a_size = 5;
    int i;
    int val;

    pp_arr = (int**)malloc(a_size * sizeof(int*));
    if(NULL == pp_arr)
    {
        puts("ERROR");
        exit(-1);
    }

    //dynamic integer allocation block
    for(i = 0; i <a_size;++i)
    {
        pp_arr[i] = (int*)malloc(sizeof(int));
        if(NULL == pp_arr[i])
        {
            puts("ERROR");
            exit(-1);
        }
    }

    //write on dyynamically allocated integeres block
    for(i=0;i<a_size;++i)
    {
        *pp_arr[i] = (i+1) * 100;
    }

    for(i = 0; i <a_size; ++i)
    {
        val = *pp_arr[i];
        printf("*pp_arr[%d]:%d\n",i,*pp_arr[i]);
    }

    free(pp_arr);
    pp_arr = NULL;

}


void arr_of_ptrs_to_date_demo(void)
{
    struct Date** ppDate_arr = NULL;
    int a_size = 5;
    int i;
    int curr_day,curr_month,curr_year;

    ppDate_arr = (struct Date**)malloc(a_size * sizeof(struct Date*));
    if(NULL == ppDate_arr)
    {
        puts("ERROR");
        exit(-1);
    }

    for(i=0;i<a_size;++i)
    {
        ppDate_arr[i] = (struct Date*)malloc(sizeof(struct Date));
        if(NULL == ppDate_arr[i])
        {
            puts("ERROR 2");
            exit(-1);
        }
    }

    for(i = 0; i <a_size;++i)
    {
        ppDate_arr[i]->day = 19-i;
        ppDate_arr[i]->month = 7-i;
        ppDate_arr[i]->year = 2025;
    }

    for(i = 0; i<a_size;++i)
    {
        curr_day =ppDate_arr[i]->day;
        curr_month= ppDate_arr[i]->month;
        curr_year = ppDate_arr[i]->year;

        printf("Date at index %d : %d / %d / %d\n",i,curr_day,curr_month,curr_year);
    }

    free(ppDate_arr);
    ppDate_arr = NULL;
}