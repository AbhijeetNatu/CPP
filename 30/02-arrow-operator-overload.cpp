#include <iostream>

void test(void);
void test2(void);

class Date
{

    private:
        int day,month,year;

    public:
        Date(int _day = 1, int _month = 11, int year = 1999)
        {

        }

        int getDay() const
        {
            return day;
        }

        int getMonth() const
        {
            return month;
        }
        int getYear() const
        {
            return year;
        }

        void setDay(int newDay)
        {
            day = newDay;
        }

        void setMonth(int newMonth)
        {
            month = newMonth;
        }

        void setYear(int newYear)
        {
            year = newYear;
        }

        void showDate(void) const
        {
            std::cout << getDay() << "/" << getMonth() << "/" << getYear() << std::endl;
        }

};

class DatePtr
{
    
    private:
        Date* pDate;

    public:
        DatePtr(Date* _pDate): pDate(_pDate)
        {
            std::cout << " Entered DatePtr::DatePtr() " << std::endl;
            std::cout << " Leaving DatePtr::DatePtr() " << std::endl;
        };

        ~DatePtr()
        {
            std::cout << " Entered DatePtr::~DatePtr() " << std::endl;
            delete pDate;
            pDate = 0;
            std::cout << " Leaving DatePtr::~DatePtr() " << std::endl;
        }

        Date* operator->()
        {
            return this->pDate;
        }


};

int main(void)
{
    test();
   // test2();      //gadbad
    return 0;
}

void test(void)
{
    Date* pDate = new Date;

    pDate->setDay(24);
    pDate->setMonth(5);
    pDate->setYear(2025);

   // std::cout << pDate->getDay() << "/" << pDate->getMonth() << "/" << pDate->getYear() << std::endl;

    pDate->showDate();

    delete pDate;
    pDate = 0;

}

void test2(void)
{
    DatePtr ptrToDate(new Date);

    int dd = ptrToDate->getDay();
    int mm = ptrToDate->getMonth();
    int yy = ptrToDate->getYear();

    ptrToDate->showDate();

}