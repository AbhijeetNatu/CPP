#include <stdio.h>
#include <stdlib.h>

struct A{
    double d;
    int* i_ptr;
};

int main(void)
{
    struct A* A_ptr = NULL;     //1

    A_ptr = (struct A*)malloc(sizeof(struct A));        //2
    if(NULL==A_ptr)         //3
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    //4
    A_ptr->d = 45.64;

    //1
    A_ptr->i_ptr = (int*)malloc(sizeof(int));
    if(NULL==A_ptr->i_ptr)
    {
        puts("ERROR IN ALLOCATING MEMORY");
        exit(-1);
    }

    *A_ptr->i_ptr = 100;

    printf("Double val = %lf,Integer val = %d\n",A_ptr->d,*A_ptr->i_ptr);

    return 0;
}