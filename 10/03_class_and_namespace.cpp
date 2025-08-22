#include <iostream>

using std::cout;
using std::endl;

//Namespace : It is a block for creating new names
//Inside namespace, we have defined following names:
namespace X{

    int num;        //data variable inside namespace

    //function inside namespace
    void test(){

        cout << "Helo World" << endl;
    }

    //class inside namespace
    class Date
    {
        private:
            int day,month,year;
        public:
            Date(){
                day = 1;
            }
    };


    typedef int xyz_t;

    namespace Y{
        int p;
    }

}

void namespace_demo(void);

int main(void)
{
    namespace_demo();

    return 0;
}


void namespace_demo()
{
    X::num = 100;
    X::test();
    X::Date myDate;
    X::xyz_t num1;
    X::Y::p = 2300;
}                                                                                                                               