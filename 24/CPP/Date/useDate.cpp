#include <iostream>
#include <cstdlib> 
#include "Date.hpp"

void testDate(void); 

int main(void)
{   
    testDate(); 
    return EXIT_SUCCESS; 
}

void testDate(void)
{
    Date* pDate = new Date(26, 4, 2025); 

    day_t day = pDate->getDay(); 
    std::cout << "day:" << day << std::endl; 

    month_t month = pDate->getMonth(); 
    std::cout << "month:" << month << std::endl; 

    year_t year = pDate->getYear(); 
    std::cout << "year:" << year << std::endl;

    pDate->show("Initial state"); 

    pDate->setDay(28); 
    pDate->setMonth(5); 
    pDate->setYear(2029); 

    pDate->show("Changed state"); 

    delete pDate; 
    pDate = 0; 
}

/* 
TODO #1 : Implement validateDateInstance() 
TODO #2 : Unit test for invalid combinations 
try
{
    pDate->setMonth(56);
}
catch(const std::domain_error& exc)
{
    std::cout << exc.what() << std::endl; 
}
*/