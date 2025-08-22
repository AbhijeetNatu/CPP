#include <iostream>
#include <string>
#include <vector>

using std::cout;            //object of class ostream  //  ostream and cout are in 
using std::endl;            //endl defined in std namespace
using std::vector;          //vector is a 'class template' defined in std namespace(header->vector)
using std::string;          //string is class defined in std namespace

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day,int init_month,int init_year)
        {
            day = init_day;
            month = init_month;
            year = init_year;
        }

        void show()
        {
            //Calling object's base address is stored in 'this'.
            //Member functions act in the context of calling object.
            //Static function do not have Calling object.

            cout << day <<"/" << month << "/" << year << endl;

        }
};


void vector_demo(void);

int main(void)
{
    vector_demo();
    return 0;
}

void vector_demo(void)
{
    //vector of ints
    vector<int> ivec1;
    vector<int> ivec2{10,20,30,40,50};
    vector<int> ivec3(ivec2);
    vector<int> ivec4(5);
    vector<int> ivec5(5,100);


    // Traverse for ivec2 
    cout <<"Printing ivec2 elements using index :" << endl;

    for(vector<int>::size_type i = 0; i != ivec2.size(); ++i)
    {
        cout << "ivec[" << i << "] : " << ivec2[i] << endl;
    }

    for (vector<int>::iterator iter = ivec2.begin(); iter != ivec2.end(); ++iter)
    {
        cout << "*iter = " << *iter << endl;
    }

    // Traverse for ivec3
    // Traverse for ivec4
    // Traverse for ivec5
}
