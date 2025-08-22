#include <iostream>

const int gc_num = 100;

int main(void)
{
    const int lc_num = 200;
    int *ptr1 = 0;
    int *ptr2 = 0;

    static const int x = 3000;      //temp variable

    /*gc_num = 1000;
    lc_num = 2000;
    ptr1 = &gc_num;
    ptr2 = &lc_num;*/

    ptr2 = const_cast<int*>(&lc_num);       //EXPLICIT TYPE CASTING In CPP

    std::cout << "Before *ptr = 2000(display via *ptr) : "  << *ptr2 << std::endl;

    *ptr2 = 2000;

    std::cout << "After *ptr = 2000(display via *ptr) : "  << *ptr2 << std::endl;

    std::cout << "Before *ptr = 2000(display via lc_num) : "  << lc_num << std::endl;

    *ptr2 = 20000;

    std::cout << "After *ptr = 20000 (display via lc_num): "  << lc_num << std::endl;

    std::cout << "After *ptr = 2000 (display via *ptr): "  << *ptr2 << std::endl;
    
    return 0;
}
