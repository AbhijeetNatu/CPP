#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void string_iterator_demo(void);

int main(void)
{
    
    string_iterator_demo();

    return  0;
}

void string_iterator_demo()
{
    string s("ABCDE");


    // 1 : Using iterator and while loop
    cout << "Repeat 1" << endl;
    string::iterator my_iter = s.begin();
    while(my_iter != s.end())
    {
        cout << "Current char : " << *my_iter << endl;
        ++my_iter;                          // PRE INCREMENT
    }


    // 2 : Using iterator and while loop
    cout << "Repeat 2" << endl;
    string::iterator my_iter1 = s.begin();
    while(my_iter1 != s.end())
    {
        cout << "Current char : " << *my_iter1 << endl;
        my_iter1++;                     // POST INCREMENT
    }
    

    // 3 : Using iterator and while loop
    cout << "Repeat 3" << endl;
    string::iterator iter_s = s.begin();
    while(iter_s != s.end())
    {
        cout << "Current char : " << *iter_s << endl;
        iter_s = iter_s + 1;                // ADDITION OF 1
    }

    // 4 : Using for loop
    cout << "Repeat using For loop" << endl;
    for(string::iterator iter_f = s.begin(); iter_f != s.end(); ++iter_f)
    {
        cout << "Iter of string " << *iter_f << endl;
    }

}

