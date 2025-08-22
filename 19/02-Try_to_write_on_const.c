#include <stdio.h> 
#include <stdlib.h> 

const int gc_num = 100; 

int main(void)
{
    const int lc_num = 200; 
    
    // gc_num = 1000; // CTE 
    // lc_num = 2000; // CTE 

    int* ptr = NULL; 

    ptr = &lc_num;  // C compiler issues warning 
                    // that it is discarding const 
    printf("Before *ptr = 1000: *ptr = %d\n", *ptr); 
    *ptr = 2000; 
    printf("After *ptr = 1000: *ptr = %d\n", *ptr); 

    // thoda next level cha knoweldge
    const int lc_num_1 = 500;
    ptr = &lc_num_1; // Compile time warning 
    printf("Before *ptr = 5000: *ptr = %d\n", lc_num_1); 
    *ptr = 5000; 
    printf("After *ptr = 5000: *ptr = %d\n", lc_num_1); 

    ptr = &gc_num; // Compile time warning 

    printf("Before *ptr = 1000, *ptr = %d\n", *ptr); // 100 
    *ptr = 1000; 
    printf("After *ptr = 1000, *ptr = %d\n", *ptr); // 1000

    puts("Application terminated successfully"); 
    return (0); 
}