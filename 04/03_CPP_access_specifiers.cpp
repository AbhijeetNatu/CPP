// TEST CODE FOR CHECKING ACCESS SPECIFIERS

#include <iostream>

using std::cout;

class Test
{
    private:
        int a;

    public :
        char b;
        float c;
};

Test g_test1;

void test_1(void);

int main(void)
{
    test_1();
    return 0;
}

void test_1(void)
{
    Test t1;

    g_test1.a = 100;
    g_test1.b = 'A';
    g_test1.c = 3.14f;

    t1.a = 200;
    t1.b == 'B';
    t1.c = 2.73f;
}