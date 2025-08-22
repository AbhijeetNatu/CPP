#include <iostream>

using std::cout;
using std::endl;


//SERVER SIDE START

class Date
{
    private:
        int day,month,year;
    public:
        void show(){
            cout << this->day << "/"<< this->month << "/"<< this->year << endl;
        }    
};
//SERVER END

//CLIENT SIDE START
int main(void)
{
    // day, month, year  of myDate will contain garbage value
    Date myDate;
    myDate.show();

    return (0);
}

//CLIENT END
