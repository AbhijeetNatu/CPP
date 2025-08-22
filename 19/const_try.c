#include <stdio.h>
#include <stdlib.h>

const int gc_num = 100;

int main(void)
{
    const int lc_num = 200;

    //gc_num = 1000;    //CTE
    //lc_num = 2000;    //CTE

    int *ptr = NULL;

    ptr = &lc_num;      //C Compiler issues warning that it is discarding const

    printf("Before *ptr = 1000 , *ptr = %d\n", *ptr);
    *ptr = 2000;
    printf("After *ptr = 1000 , *ptr = %d\n", *ptr);



    //NEXT LEVEL
    const int lc_num1= 500;

    ptr = &lc_num1;      

    printf("Before *ptr = 5000 , *ptr = %d\n", *ptr);
    *ptr = 5000;
    printf("After *ptr = 5000 , *ptr = %d\n", *ptr);

    ptr = &gc_num;          //COMPILE TIME WARNING

    printf("Before *ptr = 2000 , *ptr = %d\n", *ptr);
    *ptr = 2000;
    printf("After *ptr = 2000 , *ptr = %d\n", *ptr);


    puts("APP TERMINATED SUCCESSFULLY");

    return 0;
}