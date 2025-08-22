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

    //method: index
    cout << endl << "Printing ivec2 elements using index :" << endl;

    for(vector<int>::size_type i = 0; i != ivec2.size(); ++i)
    {
        cout << "ivec[" << i << "] : " << ivec2[i] << endl;
    }

    cout << endl<<"ivec2 iteration method : iterator :" << endl;
    for (vector<int>::iterator iter = ivec2.begin(); iter != ivec2.end(); ++iter)
    {
        cout << "*iter = " << *iter << endl;
    }

    // Traverse for ivec3
    // Traverse for ivec4
    // Traverse for ivec5

    //vector of floats
    vector<float> f_vec1;
    vector<float> f_vec2{1.1f,2.2f,3.3f,4.4f};
    vector<float> f_vec3(f_vec2);
    vector<float> f_vec4(5);        //PREallocation for 8 floats // each of them, should be 0.0f ideally but cannot be guaranteed.
    vector<float> f_vec5(8.5f);

    cout <<endl<< "f_vec2 iteration : method : index :" << endl;

    for(vector<float>::size_type i = 0; i !=f_vec2.size(); ++i)
        cout << "f_vec2[" << i <<"]:" <<f_vec2[i] << endl;

    cout <<endl <<"f_vec2 iteration method : iterator :" << endl;
    for (vector<float>::iterator iter = f_vec2.begin(); iter != f_vec2.end(); ++iter)
        cout << "*iter = " << *iter << endl;




    vector<string>  str_vec1;
    vector<string> str_vec2{
        string("Hello"),
        string("World")
    };
    vector<string> str_vec3(str_vec2);
    vector<string> str_vec4(5);
    vector<string> str_vec5(5,string("ONE"));

    //str_vec2 iteration

    cout <<endl<<"str_vec2 : iteration : method:index" << endl;
    for(vector<string>::size_type i = 0; i !=str_vec2.size();++i)
        cout <<"str_vec2[" << i <<"]:" << str_vec2[i] << endl;

        
    cout <<endl<<"str_vec2 : iteration : method:iterator" << endl;
    for(vector<string>::iterator iter = str_vec2.begin(); iter!=str_vec2.end(); ++iter)
        cout <<"iter" << *iter << endl;    

}
