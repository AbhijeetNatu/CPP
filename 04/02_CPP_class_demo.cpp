#include <iostream>

using std::cout;

class Test
{
    int a;
    char b;
    float c;
};

Test g_test_1;

void test_1(void);

int main(void)
{
    test_1();

    return 0;
}

void test_1(void)
{
    Test t1;

    //g_test_1.a = 100;
    //g_test_1.b = 'A';     //COMPILE TIME ERROR



}