#include <iostream>

using std::endl;
using std::cout;

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        // CONSTRUCTOR FUNCTION
        Date(int _day, int _month, int _year)
        {
            this->day = _day;
            this->month = _month;
            this->year = _year;
        }    

        void show()    
        {
            cout <<"Date is : "<< day << "/" << month << "/" << year << endl;
        }

};

int main(void)
{
    //Auto call - C++ first allocates 12 bytes memory for a new object of class Date, and name that memory block as d1.
    //Then, internallyit calls init() function on d1 with 9, 2,2025 as actual parameters.

    // CONSTRUCTOR acts as a callback  function for the event where new object of class is created.
    Date myDate(9,2,2025);
    //12 bytes of memeory block will be allocated to Date object
    //Make call to Date::Date(addr_of_new_object,9,2,2025);
    myDate.show();
    return 0;
}


