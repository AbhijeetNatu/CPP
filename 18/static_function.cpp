/*class Singleton             //ONLY SINGLE OBJECT IS CREATED
{
    private:
        //data
        //constructor

    public:
        static Singleton* get_Instance()
        {

        }

};
*/


#include <iostream>
class X
{
    private:
        int p,q,r;
    
    public:

        X(int _p, int _q, int _r)
        {
            this->p = _p;
            this->q = _q;
            this->r = _r;
        }

        void f1(int x)
        {
            std::cout << "--- In X::f1()---" << std::endl;

            //this keyword works here
            std::cout << this->p << " " <<this->q << " " << this->r << std::endl;

            std::cout << "X:" << x << std::endl;
        }

        static int f2(int x)
        {
            std::cout << " --- In X::f2() ---" << std::endl;

            return x;

            //this keyword is syntax error
            //std::cout << "P:" << this->p << std::endl;
        }
};


int main(void)
{
    X X1(1,2,3);
    //X::f1();
    X::f2(1);

    return 0;
}