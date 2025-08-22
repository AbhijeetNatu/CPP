#include <cstdio>

class B
{
    private:
        int num1,num2;
    
    public:
        void f()
        {
            puts("B::f()");
            printf("num1 = %d , num2 = %d\n" , num1,num2);
        }

};

class D1: virtual public B
{
    private:
        double d1,d2;
    
    public:
        void g1()
        {
            puts("D1::g1()");
        }

};

class D2 : virtual public B
{
    private:
        double d3,d4;
    
    public:
        void h()
        {
            puts("D2::h()");
        }


};

class D:public D1, public D2
{
    private:
        int a[4];
    
    public:
        void i()
        {
            puts("D::i()");
        }

};


int main(void)
{
    D objD;

    printf("sizeof(B) = %zu\n" , sizeof(B));
    printf("sizeof(D1) = %zu\n" , sizeof(D1));
    printf("sizeof(D2) = %zu\n" , sizeof(D2));
    printf("sizeof(D) = %zu\n" , sizeof(D));

    printf("address of objD = %zu\n" , reinterpret_cast<std::size_t>(&objD));
    printf("Address of instance of B inside D1:%zu\n",
    reinterpret_cast<std::size_t>(dynamic_cast<B*>(dynamic_cast<D1*>(&objD))));

    printf("Address of instance of B inside D2:%zu\n",
    reinterpret_cast<std::size_t>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))));
    
    printf("num1 in instance of B in D2: %d \n",
    *reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))));

    printf("num2 in instance of B in D2: %d \n",
    *reinterpret_cast<int*>((*reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) + 1)));

    *reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) = 1000;
    *reinterpret_cast<int*>((*reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) + 1)) = 2000;

    (dynamic_cast<B*>(dynamic_cast<D1*>(&objD)))->f();
    (dynamic_cast<B*>(dynamic_cast<D2*>(&objD)))->f();

    objD.f();

    return 0;
}

