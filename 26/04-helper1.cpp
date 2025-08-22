#include <iostream>

int get_int_1(void);
int* get_int_2(void);
int* get_int_3(void);
int* get_int_4(void);
void get_int_5(int**);
void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    int result1;
    result1 = get_int_1();

    int* ptr2 = NULL;
    ptr2 = get_int_2();

    /* 
     ptr2 will have address of freed variable num allocated in stackframe of the
     most recent call .
     Dereferencing this pointer will have an undefined result .
     That result may be a successful access to value 100.
     FREE ZALELA PRATYEK LOCATION HE UNMAPPED NASTA
    */

    //for get_int_3();
    int* ptr3 = NULL;
    ptr3 = get_int_3();
    //dont free ptr3 (will be known from help)
    
    int* ptr4 = NULL;
    ptr4 = get_int_4();
    free(ptr4);
    ptr4 = NULL;

    int* ptr5 = NULL;
    get_int_5(&ptr5);
    //ptr5 contains valid address
    free(ptr5);
    ptr5 = NULL;
}

int get_int_1(void)
{
    return 100;
}

int* get_int_2(void)
{
    int num = 100;
    return (&num);
    // You return address of memory block which will no longer exists when control flow reaches to caller
    // yet caller will have address of freed memory block in it's pointer making it a dangling pointer
}

int* get_int_3(void)
{
    static int num = 100;
    
    /*
    STATIC qualifier has changed timer of allocation at the time of building exe and not at time of making
    a function call , frequency of allocation (only once instead of per function call), 
    lifetime(equal to lifetime of program instead of lifetime of function call) and storage
    section (data/bss/lcomm instead of stack). 
    */

    /*
        Lifetime alteration plays a key role here.
        because static variable is not freed at the time of returning a function,
        returning it's address does not make a caller's pointer a dangling pointer.
    */

    return(&num);
}


////////////////////////////////////////////////////////////////////

//memory management wise safe , thread safe
//downside -> caller should know that it must free the address which returned
int* get_int_4(void)
{
    int* ptr = NULL;

    ptr = (int*)malloc(sizeof(int));

    return ptr;
}

void get_int_5(int** ppInt)
{
    *ppInt = (int*)malloc(sizeof(int));
}