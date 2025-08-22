//header file inclusion
#include <iostream>

//import symbols cout and endl from standard namespace
using std::cout;
using std::endl;


// SERVER SIDE START
class Date
{
    private:
        //data layout definition
        int day;
        int month;
        int year;
    public:
        //public member functions
        //FIRST PARAMETER OF init() function is ""Date* this""
        void init(int init_day,int init_month, int init_year)
        {
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
        }

        //FIRST PARAMETER OF show() is ""Date* this""
        void show()
        {
            cout << this->day << "/" << this->month << "/" << this->year << endl;
        }

};

//SERVER SIDE END


// CLIENT SIDE START
int main(void)
{
    //Create an object of class Date
    Date d1;

    // Use object of class Date
    cout <<"d1 object before calling init() function" <<endl;
    d1.show();
    d1.init(8,2,2025);
    cout <<"d1 object after calling init() function" <<endl;
    d1.show();

    return 0;
}

//CLIENT SIDE END