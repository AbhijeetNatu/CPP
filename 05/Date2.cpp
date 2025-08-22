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
            cout << "Date : " << this->day << "/" << this->month << "/" << this->year << endl;
            cout << "********** LEAVE Date::show() ***********" << endl;
        }
};

// Main function
int main(void)
{
    //Define three local objects of class Date
    Date d1,d2,d3;

    //Define three pointers to class Date
    Date* pDate1 = 0;       //pDate1 is a pointer to class Date
    Date* pDate2 = 0;
    Date* pDate3 = 0;

    // Set pointers to addresses
    pDate1 = &d1;
    pDate2 = &d2;
    pDate3 = &d3;

    //For d1
    pDate1->day = 22;
    pDate1->month = 10;
    pDate1->year = 1998;         //12 bytes
    /*d1.day = 22;
    d1.month = 10;
    d1.year = 1998;*/         //12 bytes

    //For d2
    pDate2->day = 02;
    pDate2->month = 02;
    pDate2->year = 2025;         //12 bytes

    //For d3
    pDate3->day = 15;
    pDate3->month = 10;
    pDate3->year = 2002;         //12 bytes

    // For d1
    //object d1
    cout << "main():Making use of pointer pDate1 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd1' is: " << pDate1 <<endl;
    pDate1->show();

    // For d2 
    cout << "main():Making use of pointer pDate2 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd2' is: " << pDate2 <<endl;
    pDate2->show();

    // For d3
    cout << "main():Making use of pointer pDate3 to make a call to Date::show()\n" << endl;
    cout <<"main() : Address of object 'd3' is: " << pDate3 <<endl;
    pDate3->show();

    return(0);
}

