#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i; 
    int n; 
    int j; 
    int m; 

    i = 10; 
    n = i++; 
    printf("i = %d, n = %d\n", i, n); // i == 11, n == 10 

    j = 20; 
    m = ++j; 
    printf("j = %d, m = %\n", j, m); // j == m == 21

    return (0); 
}

