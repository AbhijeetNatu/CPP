#ifndef _DATE_HPP 
#define _DATE_HPP 

// no additional include files 

// symbolic constants (const)
const int E_INVALID_DATE    = -1; 
const int VALID_DATE        = 1; 

// typedefs 
typedef int day_t; 
typedef int month_t; 
typedef int year_t; 
typedef int status_t; 

// type definitions 
class Date 
{
    private: 
        day_t day; 
        month_t month; 
        year_t year; 
        static status_t validateDateInstance(day_t day, month_t month, year_t year); 
    public: 
        Date(day_t init_day, month_t init_month, year_t init_year); 
        day_t getDay() const; 
        month_t getMonth() const; 
        year_t getYear() const; 
        void setDay(day_t newDay); 
        void setMonth(month_t newMonth); 
        void setYear(year_t newYear); 
        void show(const char* msg = 0); 
}; 

// no global C like function 

#endif // _DATE_HPP