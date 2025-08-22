#include <iostream>

struct MassAndDistance_1 
{
    double m1;
    double m2;
    double r;
};

class MassAndDistance_2 
{
    double m1;
    double m2;
    double r;
};

int main(void)
{
    using std::cout;
    using std::endl;

    //Client
    struct MassAndDistance_1 X1;
    MassAndDistance_2 X2;


    //CLIENT is accessing the internal members of the product he/she has bought
    X1.m1 = 1.1;
    X1.m2 = 2.2;
    X1.r = 3.3;

    /*
    X2.m1 = 1.1;        //ERROR as class variables are not by default accessible
    X2.m2 = 2.2;
    X2.r  = 3.3;
    */
   
    return 0;



}