#include <iostream>
#include <cstdlib>

class Date{

    private:
        int day,month,year;

    public: 
    //CONSTRUCTOR is implemented but cannot be called after dynamiclally allocating Date object using malloc
        Date(int init_day,int init_month,int init_year)
        {
            std::cout << "----ENTER IN Date::Date()---" << std::endl;
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
            std::cout << " ---- LEAVING Date::Date() ----" << std::endl;
        }

        void init(int init_day,int init_month,int init_year)
        {
            std::cout << "----ENTER IN Date::Date()---" << std::endl;
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
            std::cout << " ---- LEAVING Date::Date() ----" << std::endl;
        }


        void show(){
            std::cout << day <<"/" << month<<"/" << year << std::endl;
        }
};

int main(void)
{
    Date* pDate = (Date*)malloc(sizeof(Date));

    if(NULL == pDate)
    {
        std::cout << "Error" << std::endl;
        exit(-1);
    }

    pDate->init(16,3,2025);


    pDate->show();          //GARBAGE VALUE

    free(pDate);
    pDate = NULL;

    return 0;
}

