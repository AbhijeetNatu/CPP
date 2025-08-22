#include <iostream>

class A
{
    private:
        double d;
        int* iptr;

    public:
        A(double _d, int _n)
        {
            std::cout << "-----In A::A()-----" << std::endl;
            this->d = _d;
            this->iptr = new int;
            *this->iptr = _n;
            std::cout << "-----Leaving A::A()-----" << std::endl;
        }

        ~A()
        {
            std::cout << "-----In A::~A()-----" << std::endl;
            delete this->iptr;
            this->iptr = 0;
            std::cout << "Leaving A::~A()----" << std::endl;
        }

        void show()
        {
            std::cout << "in A :: show()  Double val:" << this->d << ","
            << "Int Val: " << this->iptr << std::endl;
        }
};


class B
{
    private:
        float f_arr[4];
        A* A_ptr;
        int i_arr[4];
    
    public:
        B()
        {
            std::cout << "-----In B::B()-----" << std::endl;
            memset((void*)f_arr,0,4*sizeof(float));
            memset((void*)i_arr,0,4*sizeof(float));
            A_ptr = new A(45.56,100);
            std::cout << "-----Leaving B::B()-----" << std::endl;
        }

        void show()
        {
            std::cout << "-----ENTER B::show()------" << std::endl;
           
            std::cout << "showing f_arr:" << std::endl;
            for(int i=0;i<4;++i)
            {
                std::cout << "f_arr[" << i <<"]:" << this->f_arr[i] << std::endl;
            }

            std::cout << "showing i_arr:" << std::endl;
            for(int i=0;i<4;++i)
            {
                std::cout << "i_arr[" << i <<"]:" << this->i_arr[i] << std::endl;
            }

            std::cout << "showing A_ptr:" << std::endl;
            this->A_ptr->show();

            std::cout << "-----LEAVING B::show()------" << std::endl;
        }

        ~B()
        {
            std::cout << "-----In A::~B()-----" << std::endl;
            delete this->A_ptr;
            this->A_ptr = 0;
            std::cout << "Leaving A::~B()----" << std::endl;
        }
};

int main(void)
{
    B* pB = new B;
    std::cout << "B* pB = new B OVER"<< std::endl;

    pB->show();

    delete pB;

    pB = 0;

    return 0;
}