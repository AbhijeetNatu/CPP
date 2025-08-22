#include <iostream>
#include "insertionSort.hpp"

int main(void)
{
    int iArr[5] = {500,200,300,100,400};
    double dArr[5] = {5.5,2.2,1.1,4.4,3.3};

    show<int>(iArr,5,"Before Sort : ");
    insertionSort<int>(iArr,5);
    show<int>(iArr,5,"After Sort : ");

    show<double>(dArr,5,"Before Sort : ");
    insertionSort<double>(dArr,5);
    show<double>(dArr,5,"After Sort : ");
}