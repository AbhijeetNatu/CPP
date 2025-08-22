#include <iostream>
#include <typeinfo>

class CPA_int
{

    private:
        int num;
    public:
        CPA_int(int _num = 0) : num(_num)
        {

        }

        CPA_int add(const CPA_int& other)           //const pointer to pointer to const
        {
            CPA_int temp;
            temp.num = this->num + other.num;
            return temp;
        }

        void show() const
        {
            std::cout << "Internal num Value : " << this->num << std::endl;
        }
};

int main(void)
{
    CPA_int n1(100);         //Internal num value will be 0
    CPA_int n2(200);    // Internal number value will be 200
    CPA_int sum;

    std::cout << "main(): Showing internal values of n1,n2,sum." << std::endl;

    n1.show();
    n2.show();
    sum.show();

   // sum  = n1 + n2; //ERROR HERE  :: Binary operator is not defined on objects of type CPA_int and CPA_int
   sum = n1.add(n2);    // this will work

   std::cout << "main(): Showing internal values of n1,n2,sum AFTER sum = n1.add(n2);" << std::endl;

   n1.show();
   n2.show();
   sum.show();

}