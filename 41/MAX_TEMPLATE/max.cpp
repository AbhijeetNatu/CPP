#include <iostream>
#include "max.hpp"

void myfunc1(void);
void mytemplatefunc(void);

int main(void)
{
    int x = 10, y = 20;
    double p = 1.1, q = 2.2;
    
    myfunc1();
    mytemplatefunc();

    return 0;
}

void myfunc1(void)
{
    int result = max(50,100);

    std::cout << "Max out of the 2 values is : " << result << std::endl;
}

void mytemplatefunc(void)
{
    //TEMPLATE 
    int x = 70, y = 30;
    int iMaxResult = max<int>(x,y);
    
    std::cout << "Max(mytemplatefunc) : int.. out of the 2 values is : " << iMaxResult << std::endl;

    double p = 19831 , q = 24712;
    double dMaxResult = max<double>(p,q);

    std::cout << "Max(mytemplatefunc) : double.. out of the 2 values is : " << dMaxResult << std::endl;
}



/*
    CAN BE PASSED BY REFERENCE 
    const int& a = x;
    const int& b = 10;
    int const& c = 20;
*/