// ERROR WALA CODE


#include <iostream>

using std::cout;


class Date
{
    public:
    int day;
    int month;
    int year;
    

    void show(Date* pDate)
    {
        cout <<pDate->day << "/" << pDate->month << "/" << pDate->year << "\n";
    }
};


int main(void)
{
    Date myBirthDate;

    myBirthDate.day = 22;
    myBirthDate.month = 10;
    myBirthDate.year = 1998;

    Date::show(&myBirthDate);

    return 0;
}