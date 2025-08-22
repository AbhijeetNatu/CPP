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


        void show(){
            std::cout << day <<"/" << month<<"/" << year << std::endl;
        }
};

//new = malloc() + automatic call to constructor

//delete =  automatic call to destructor + free()


//Date* pDate;

int main(void)
{
    Date* pDate = 0;
    pDate = new Date(16,03,2025);

    pDate->show();

    delete(pDate);
    pDate = 0;

    return 0;
}


//g++ -S -o 04_new_and_delete_demo.s 04_new_and_delete_demo.cpp