extern int num;
extern void test_function(void);

int main(void)
{
    num = 10;

    test_function();

    return 0;
}