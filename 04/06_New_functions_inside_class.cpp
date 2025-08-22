#include <iostream>

using std::cout;


class Date
{
    public:
        int day;
        int month;
        int year;

        void show()
        {
            cout <<this->day << "/" << this->month << "/" << this->year << "\n";
        }
};


int main(void)
{
    Date myBirthDate;

    myBirthDate.day = 22;
    myBirthDate.month = 10;
    myBirthDate.year = 1998;

    //Date::show(&myBirthDate);

    myBirthDate.show(); //converted internally to  Date::show(&myBirthDate);

    return (0);
}
