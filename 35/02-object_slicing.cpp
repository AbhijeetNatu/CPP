#include <iostream>

class B1
{
    public:
        int n1,n2;
};

class B2
{
    public:
        double d1,d2;

        void test()
        {
            printf("In B2::test():addr(this):%zu\n", (std::size_t)this);
        }
};

class D: public B1,public B2
{
    public:
        short s1,s2,s3,s4;

        void print_slices()
        {
            std::size_t off_B1 = (std::size_t)(&this->n1) - (std::size_t)this;
            std::size_t off_B2 = (std::size_t)(&this->d1) - (std::size_t)this;
            std::size_t offD = (std::size_t)(&this->s1) - (std::size_t)this;

            printf("offB1 = %zu\noffB2 = %zu\noffD = %zu\n", off_B1 , off_B2 , offD);
        }
};

int main(void)
{
    printf("sizeof(B1) = %zu \n", sizeof(B1));
    printf("sizeof(B2) = %zu \n", sizeof(B2));
    printf("sizeof(D) = %zu \n", sizeof(D));

    D objD;

    objD.print_slices();

    printf("address of objD:%zu\n", (std::size_t)&objD);

    objD.test();

    return 0;
}