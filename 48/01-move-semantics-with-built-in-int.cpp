#include <iostream>

int main(void)
{
    //HERE NO DIFFERENCE BETWEEN COPY AND MOVE 

    int n = 100;
    int m1 = 0;

    std::cout << "Before m1 = n;" << std::endl;
    std::cout << "n : " << n << ", m1 : " << m1 << std::endl;

    m1 = n;

    std::cout << "After m1 = n;" << std::endl;
    std::cout << "n : " << n << ", m1 : " << m1 << std::endl;

    int m2 = 0;

    std::cout << "Before m2 = std::move(n);" << std::endl;
    std::cout << "n : " << n << ", m2 : " << m2 << std::endl;

    //HERE ONLY TYPECASTING DONE IN R-VALUE REFERENCE FOR MOVE SEMANTICS
    m2 = std::move(n);
    std::cout << "After m2 = std::move(n);" << std::endl;
    std::cout << "n : " << n << ", m2 : " << m2 << std::endl;

    //HERE SEE THE DIFFERENCE (ACTUAL MOVE SEMANTICS) WHEN POINTER COMES IN PICTURE
    int* p1 = &n;
    int* p2 = 0;

    std::cout << "Before p2 = std::move(p1);" << std::endl;
    std::cout << std::hex <<"p1 : " << p1 << ", p2 : " << p2 << std::endl;

    p2 = std::move(p1);

    std::cout << "After p2 = std::move(p1);" << std::endl;
    std::cout << std::hex <<"p1 : " << p1 << ", p2 : " << p2 << std::endl;

    return 0;
}
