#include <iostream>


class Date
{
    friend std::istream& operator>>(std::istream& is , Date& refDate);
    friend std::ostream& operator<<(std::ostream& os, const Date& refDate);
    private:
        int day,month,year;

    public:
        Date(int _day = 1, int _month = 11, int year = 1999)
        {

        }
};

std::ostream& operator<<(std::ostream& os, const Date& refDate)
{
    os << refDate.day << "/" << refDate.month << "/" << refDate.year ;

    return os;
}


std::istream& operator>>(std::istream& is , Date& refDate)
{
    std::cout << " Enter Day :";
    is >> refDate.day;
    std::cout << " Enter Month :";
    is >> refDate.month;
    std::cout << " Enter Year :";
    is >> refDate.year;

    return is;
    
}

void test1(void);

int main(void)
{

    test1();
    
    return 0;
}


void test1(void)
{
    Date myDate;
    std::cout << "In Test1" << std::endl;
    std::cin >> myDate ;
    std::cout << myDate;
}
