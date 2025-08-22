#include <iostream> 
#include <stdexcept> 
#include "Date.hpp"

Date::Date(day_t init_day, month_t init_month, year_t init_year)
{
    if(validateDateInstance(init_day, init_month, init_year) != VALID_DATE)
        throw std::domain_error("Invalid combination of day, month and year"); 
    
    day = init_day; 
    month = init_month; 
    year = init_year; 
}

day_t Date::getDay() const
{
    return (day); 
}

month_t Date::getMonth() const
{
    return (month); 
}

year_t Date::getYear() const
{
    return (year); 
}

void Date::setDay(day_t newDay)
{
    if(validateDateInstance(newDay, this->month, this->year) != VALID_DATE)
        throw std::domain_error("Invalid value for new day"); 
    this->day = newDay; 
}

void Date::setMonth(month_t newMonth)
{
    if(validateDateInstance(this->day, newMonth, this->year) != VALID_DATE)
        throw std::domain_error("Invalid value for new month"); 
    this->month = newMonth; 
}

void Date::setYear(year_t newYear)
{
    this->year = newYear; 
}

void Date::show(const char* msg)
{
    if(msg)
        std::cout << msg << ":"; 
    std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
}

status_t Date::validateDateInstance(day_t day, month_t month, year_t year)
{
    return VALID_DATE; 
}