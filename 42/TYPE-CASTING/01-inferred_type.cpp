#include <iostream>

int main(void)
{

    int a = 10, b = 20;

    std::cout << "type(a+b):" << typeid(a+b).name() << std::endl;           // int
    std::cout << "type(a+b):" << typeid((float)(a+b)).name() << std::endl;      // float OVERWRITE type
    std::cout << "type(a+b):" << typeid((a+b)).name() << std::endl;         // int

    return 0;
}
