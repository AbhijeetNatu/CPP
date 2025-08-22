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
            cout << endl << "***** DATE CONSTRUCTOR ENTER *****" << endl << endl;
            cout << "Address of newly allocated object : " << this << endl << endl;
            this->day = _day;
            this->month = _month;
            this->year = _year;
            cout << "***** DATE CONSTRUCTOR LEAVE *****" << endl << endl;
        }    

        void show()    
        {
            cout <<"***** Date::show() ENTER *****"<< endl << endl;
            cout <<"Address of object whose members must be shown : "<< this << endl << endl;
            cout <<"Date is : "<< day << "/" << month << "/" << year << endl << endl;
            cout <<"***** Date::show() LEAVE *****"<< endl;
        }

};

int main(void)
{
    // Memory allocation of 12 bytes of stack frame of main() + call to constructor
    Date myDate(9,2,2025);

    // Memory allocation of 12 bytes of stack frame of main() + call to constructor
    Date cpaBirthDate(1,01,2025);
    //12 bytes of memeory block will be allocated to Date object
    //Make call to Date::Date(addr_of_new_object,9,2,2025);

    cout << "main():address of myDate: " << &myDate << endl;
    cout << "main():address of cpaBirthDate: " << &cpaBirthDate << endl;

    myDate.show();
    cpaBirthDate.show();
    return 0;
}


