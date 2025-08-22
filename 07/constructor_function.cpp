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
    Date myDate(9,2,2025);
    //12 bytes of memeory block will be allocated to Date object
    //Make call to Date::Date(addr_of_new_object,9,2,2025);
    myDate.show();
    return 0;
}


