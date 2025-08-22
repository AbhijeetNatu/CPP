#include <iostream>

class Date
{
    private:
        int day,month,year;
    
    public:
        Date(int _dd,int _mm,int _yy) : day(_dd),month(_mm),year(_yy)
        {

        }
};


int main(void)
{
    Date myDate(18,5,2025);

    std::cout << myDate;

}

