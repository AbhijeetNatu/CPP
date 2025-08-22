#include <iostream>
#include <cstdlib>
#include <cassert>


struct IntPtr
{
    int *p;
    int ref_count;
};


class HasPtr
{
    private:
        int n;
        struct IntPtr* pPtr;

    public:
        //parameterised constructor
        HasPtr(int _n, int data)
        {
            n = _n;
            
            pPtr = new IntPtr;
            pPtr->p = new int(data);
            
            *pPtr->p = data;
            pPtr->ref_count = 1;
        }

        int getn() const
        {
            return n;
        }

        void setn(int newN)
        {
            this->n = newN;
        }

        struct IntPtr* getPtr() const
        {
            return this->pPtr;
        }

        int *getp() const
        {
            return this->pPtr->p;
        }

        int getVal() const
        {
            return *this->pPtr->p;
        }

        void setVal(int newVal)
        {
            *this->pPtr->p = newVal;
        }

        int getRefCount() const
        {
            return this->pPtr->ref_count;
        }
};


void test1(void);

int main(void)
{

   test1();


    return 0;
}


void test1(void)
{
    HasPtr hp1(100,200);
    HasPtr hp2(200,300);

    std::cout << std::endl <<  "Address in hp1 and hp2 must be distinct.." << std::endl;
    std::cout << "hp1.pPtr : " << std::hex << hp1.getPtr() << std::endl;
    std::cout << "hp2.pPtr : " << std::hex << hp2.getPtr() << std::endl<<std::endl;

    std::cout << "Printing hp1.pPtr->p & hp2.pPtr->p" << std::endl;
    std::cout << "hp1.pPtr->p : " << std::hex << hp1.getp() << std::endl;
    std::cout << "hp2.pPtr->p : " << std::hex << hp2.getp() << std::endl<<std::endl;

    std::cout << "Printing integer pointed by reference counted pointer: " << std::endl;
    std::cout << "*hp1.pPtr->p : " << std::dec << hp1.getVal() << std::endl;
    std::cout << "*hp2.pPtr->p : " << std::dec << hp2.getVal() << std::endl<<std::endl;

    std::cout << "Printing reference count of reference counted pointer: " << std::endl;
    std::cout << "hp1.pPtr-ref_count: " <<std::dec << hp1.getRefCount() << std::endl;
    std::cout << "hp2.pPtr-ref_count: " <<std::dec << hp2.getRefCount() << std::endl;
}
