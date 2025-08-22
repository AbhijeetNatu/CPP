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

        //Copy constructor
        HasPtr(const HasPtr& other)
        {
            this->n = other.n;
            this->pPtr = other.pPtr;
            this->pPtr->ref_count += 1;
        }

        HasPtr& operator=(const HasPtr& other)
        {
            if(this == &other)
                return *this;
            
            // LHS and RHS are distinct objects

            this->pPtr->ref_count -= 1;
            if(this->pPtr->ref_count == 0)
            {
                std::cout <<std::endl<< "HasPtr::operator=():Ref Count == 0 , deleting internal pointer " << std::endl;
                delete this->pPtr->p;
                delete this->pPtr;
            }

            this->pPtr = other.pPtr;
            this->pPtr->ref_count +=1;

            return *this;
        }

        ~HasPtr()
        {
            std::cout << std::endl << "HasPtr::~HasPtr(): Before decrementing refcount:" << this->pPtr->ref_count << std::endl;
            this->pPtr->ref_count -=1;
            std::cout << "HasPtr::~HasPtr(): After decrementing refcount:" << this->pPtr->ref_count << std::endl;
            if(this->pPtr->ref_count == 0)
            {
                std::cout << "Destroying internal pointers " << std::endl;
                delete this->pPtr->p;
                delete this->pPtr;
            }
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

void test2(void);

int main(void)
{

    test1();
    test2();
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


void test2(void)
{
    HasPtr* php1 = new HasPtr(100,200);
    std::cout << std::endl <<"HasPtr* php1 = new HasPtr(100,200)" << std::endl;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       //1

    std::cout << std::endl <<"HasPtr* php2 = new HasPtr(*php1)" << std::endl;
    HasPtr* php2 = new HasPtr(*php1);
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       //2
    std::cout << "php2->getRefCount(): " << php2->getRefCount() << std::endl;       //2

    std::cout << std::endl <<"HasPtr* php3 = new HasPtr(*php2)" << std::endl;    
    HasPtr* php3 = new HasPtr(*php2);
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       //3
    std::cout << "php2->getRefCount(): " << php2->getRefCount() << std::endl;       //3
    std::cout << "php3->getRefCount(): " << php3->getRefCount() << std::endl;       //3

    std::cout <<  std::endl <<"HasPtr* php4 = new HasPtr(1000,2000)" << std::endl;
    HasPtr* php4 = new HasPtr(1000,2000);
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       //1

    std::cout << std::endl <<"HasPtr *php5 = new HasPtr(*php4)" << std::endl;
    HasPtr *php5 = new HasPtr(*php4);
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       //2
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;       //2

    std::cout << std::endl <<"*php4 = *php3" << std::endl;
    *php4 = *php3;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       //4
    std::cout << "php2->getRefCount(): " << php2->getRefCount() << std::endl;       //4
    std::cout << "php3->getRefCount(): " << php3->getRefCount() << std::endl;       //4
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       //4
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;       //1

    std::cout << std::endl << "*php5 = *php2" << std::endl;
    *php5 = *php2;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       //5
    std::cout << "php2->getRefCount(): " << php2->getRefCount() << std::endl;       //5
    std::cout << "php3->getRefCount(): " << php3->getRefCount() << std::endl;       //5
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       //5
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;       //5


    std::cout << std::endl << "delete php2" << std::endl;

    delete php2;
    php2 = 0;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;       
    std::cout << "php3->getRefCount(): " << php3->getRefCount() << std::endl;      
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;       

    std::cout << std::endl << "delete php3" << std::endl;

    delete php3;
    php3=0;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;      
    std::cout << "php4->getRefCount(): " << php4->getRefCount() << std::endl;       
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;    
    

    std::cout << std::endl << "delete php4" << std::endl;
    delete php4;
    php4=0;
    std::cout << "php1->getRefCount(): " << php1->getRefCount() << std::endl;      
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;    


    std::cout <<  std::endl << "delete php1" << std::endl;
    delete php1;
    php1=0;
    std::cout << "php5->getRefCount(): " << php5->getRefCount() << std::endl;    

    
    std::cout << std::endl << "delete php5" << std::endl;
    delete php5;
    php5=0;


    std::cout << "REF COUNT DELETE RIGOROUS TEST OVER"<< std::endl;    
}