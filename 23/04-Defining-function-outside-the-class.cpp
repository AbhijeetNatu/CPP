#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month;
        int year; 
    public: 
        Date(int, int, int); 
        int getDay() const; 
        int getMonth() const; 
        int getYear() const; 
        void setDay(int newDay); 
        void setMonth(int newMonth); 
        void setYear(int newYear); 
        void show() const; 
}; 

Date::Date(int initDay, int initMonth, int initYear) : day(initDay), month(initMonth), year(initYear)
{

} 

int Date::getDay() const
{
    return (day); 
}

int Date::getMonth() const
{
    return (month); 
}

int Date::getYear() const
{
    return (year); 
}

void Date::setDay(int newDay)
{
    this->day = newDay; 
}

void Date::setMonth(int newMonth)
{
    this->month = newMonth; 
}

void Date::setYear(int newYear)
{
    this->year = newYear; 
}

void Date::show() const
{
    std::cout << day << "/" << month << "/" << year << std::endl; 
}

int main(void)
{
    // create and use date object 
    return (0); 
}
