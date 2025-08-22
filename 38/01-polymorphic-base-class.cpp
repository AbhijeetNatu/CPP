#include <iostream>
#include <typeinfo>     //for typeid() operator

class Base
{
    public:
    //Default constructor
        Base()
        {

        }

        virtual void f()        //polymorphism
        {

        }
};

class Derived : public Base
{
    public:
    //Default constructor
        Derived() : Base()
        {

        }
};

int main(void)
{

    Base* objBase = new Base();

    std::cout << "Type of *objBase: " << typeid(objBase).name() << std::endl;

    Derived* objDerived = new Derived();

    std::cout << "Type of *objDerived : " << typeid(objDerived).name() << std::endl;

    return 0;
}
