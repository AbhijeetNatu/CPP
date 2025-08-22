#include <iostream>

using std::cout;
using std::endl;        // use this for '\n' (END OF LINE)

// Class
class Date {

    public:
        int day;
        int month;
        int year;

        void show(){

            cout << "********** ENTER Date::show() ***********" << endl;
            cout << "Address of object used for making the current call :  " << this <<endl;
            cout << this->day << "/" << this->month << "/" << this->year << endl;
            cout << "********** LEAVE Date::show() ***********" << endl;
        }
};

// Main function
int main(void)
{
    Date d1,d2,d3;

    //For d1
    d1.day = 22;
    d1.month = 10;
    d1.year = 1998;         //12 bytes

    //For d2
    d2.day = 02;
    d2.month = 02;
    d2.year = 2025;         //12 bytes

    //For d3
    d3.day = 15;
    d3.month = 10;
    d3.year = 2002;         //12 bytes

    // For d1
    cout << "main():Making use of object d1 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd1' is: " << &d1 <<endl;
    d1.show();

    // For d2 
    cout << "main():Making use of object d2 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd2' is: " << &d2 <<endl;
    d2.show();

    // For d3
    cout << "main():Making use of object d3 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd3' is: " << &d3 <<endl;
    d3.show();

    return(0);
}

