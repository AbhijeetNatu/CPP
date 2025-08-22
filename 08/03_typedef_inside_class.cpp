#include <iostream>

using std::cout;
using std::endl;


class Date
{
    public:
        typedef int day_t;
        typedef int month_t;
        typedef int year_t;
    private:
        day_t day;
        month_t month;
        year_t year;
    public:
        Date(day_t init_day,month_t init_month, year_t init_year)
        {
            day = init_day;             //this->day
            month = init_month;         //this->month
            year  = init_year;          //this->year
        }

        day_t getDay(void)
        {
            return day;
        }

        month_t getMonth(void)
        {
            return month;
        }

        year_t getYear(void)
        {
            return year;
        }

};


int main(void)
{
    Date d1(15,02,2025);

    //d1.getDay();        //Date::getDay(&d1);

    Date::day_t myDay = d1.getDay();

    cout <<endl << "typeDef Day inside Date::day_t : " << myDay << endl;
    cout <<endl << "typeDef Month inside Date::month_t : " << d1.getMonth() << endl;
    cout <<endl << "typeDef Year inside Date::year_t : " << d1.getYear() << endl;

    cout <<endl << "Day  : " << d1.getDay() << endl;
    cout << "Month  : " << d1.getMonth() << endl;
    cout << "Year  : " << d1.getYear() << endl;

    return 0;
}
