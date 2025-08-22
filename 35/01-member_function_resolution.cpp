#include <iostream>

class Base
{
    public:
        //Inheritor
        void f()
        {
            std::cout << "Base::f()" << std::endl;
        }

        // Will be overriden by Derived class 
        // but not made virtual in base class
        void g1()
        {
            std::cout << "Base::g1()" << std::endl;
        }

        //Will be overriden by derived class
        // For extension: Will be made virtual in Base
        virtual void g2()
        {
            std::cout << "Base::g2() :(VIRTUAL)" << std::endl;
        }

        // Will be overriden by Derived class
        // For Replacement : Will be made Virtual in Base
        virtual void g3()
        {
            std::cout << "Base::g3() :(VIRTUAL)" << std::endl;
        }

};

class Derived : public Base
{
    public:

        //Overriding Base::g1() , but Base::g1() IS NOT VIRTUAL
        void g1()
        {
            std::cout << "Derived::g1()" << std::endl;
        }
        //Overriding Base::g2() for Extending
        void g2()
        {
            // this = Calling object of type Derived
            // Only calling g2() or calling this->g2() will result in
            // recursive call to g2()
            std::cout <<"In Derived::g2()"<< std::endl;
            std::cout <<"Calling Base::g2() for extension"<< std::endl;
            this->Base::g2();
            std::cout <<"Derived::g2() : Derived Specific Logic"<< std::endl;
            std::cout <<"Returning from Derived::g2()"<< std::endl;
        }

        //Overriding Base::g3()
        void g3()
        {
            std::cout <<"Derived::g3()" << std::endl;
        }

        void h()
        {
            std::cout << "Derived::h()" << std::endl;
        }
};

void testWithDerivedPtr(void);
void testWithBasePtr(void);

int main(void)
{
    testWithDerivedPtr();
    testWithBasePtr();

    return 0;
}

void testWithDerivedPtr()
{
    Derived* pD = new Derived;

    //INHERITOR Base::f()
    pD->f();

    // OVERRIDDEN BY DERIVED BUT NOT MADE VIRTUAL
    //Base::g1()
    pD->Base::g1(); //C++ HAS TO SEARCH FOR BASE            //WORKED BECAUSE POINTER IS DERIVED TYPE

    // OVERRIDDEN BY DERIVED FOR EXTENSION : MADE VIRTUAL
    //Base::g2()
    pD->Base::g2();

    // OVERRIDDEN BY DERIVED FOR REPLACEMENT : MADE VIRTUAL
    //Base::g3()
    pD->Base::g3();

    //Derived::g1()
    pD->g1();

    //Derived::g2()
    pD->g2();
    
    //Derived::g3()
    pD->g3();

    //DERIVED SPECIFIC FUNCTION
    //Derived::h()
    pD->h();

    delete pD;
    pD = 0;

}

void testWithBasePtr()
{
    Base* pB = new Derived;

    // Base::f()
    pB->f();

    // Base::g1()
    pB->g1();

    // Base::g2()
    pB->Base::g2();           //As g2() is virtual          

    // Base::g3()
    pB->Base::g3();          //As g3() is virtual , we need to specify that we want to call function from Base Class

    // Derived::g1()        
    //pB->Derived::g1();        // THIS WILL NOT WORK
    dynamic_cast<Derived*>(pB)->g1();

    // Derived::g2()
    pB->g2();

    // Derived::g3()
    pB->g3();

    // Derived::h()
    //pB->h();              // THIS WILL NOT WORK
    dynamic_cast<Derived*>(pB)->h();

    delete pB;
    pB = 0;
}
