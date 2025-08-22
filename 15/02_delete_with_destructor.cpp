#include <iostream>

class A
{
    private:
        double d;
        int* iptr;

    public:
        A(double _d, int _n)
        {
            this->d = _d;
            this->iptr = new int;
            *this->iptr = _n;
        }

        ~A()
        {
            delete this->iptr;
            this->iptr = 0;
        }

        void show()
        {
            std::cout << "Double val:" << this->d << ","
            << "Int Val: " << this->iptr << std::endl;
        }
};


int main(void)
{
    A* A_ptr = 0;
    A_ptr = new A(45.5,100);
    A_ptr->show();
    delete A_ptr;

    A_ptr = NULL;
    return 0;
}

/*
SYNTAX OF DESTRUCTOR

1. like constructor, destrucotr is a public memver function
2. Like constructor, destructor does not have return type annotation
3. Like constructor, name of destructor also dependent on class name.
4. destructor name = ~ tilde 

*/