#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void string_demo(void)
{
    //STRING :  DYYNAMICALLY RESIZABLE CHARACTER ARRAY
    string s1;
    string s2("hello");
    string s3(s2);

    cout << "s1:"<< s1 << endl;
    cout << "s2:"<< s2 << endl;
    cout << "s3:"<< s3 << endl;

    for(string::size_type  i = 0; i!=s2.size(); ++i)
        cout << "s2["  <<  i << "]:" << s2[i] << endl;

    
    for(string::iterator  iter = s2.begin();
        iter != s2.end();
        ++iter)
        cout << "iter = "  <<  *iter << endl;
}


void vector_demo(void)
{
    vector<int> i_vec;
    vector<double> d_vec;

    i_vec.push_back(100);
    i_vec.push_back(200);
    i_vec.push_back(300);


    cout <<  "ivec by index:" <<endl;
    for(vector<int>::size_type i = 0; i < i_vec.size(); ++i)
        cout << "ivec["  << i <<  "]:" << i_vec[i] << endl;

    cout <<  "ivec by iterator:" <<endl;
    for(vector<int>::iterator iter = i_vec.begin(); iter != i_vec.end(); ++iter)
        cout << "*iter:"  << *iter << endl;    

}

int main(void)
{
    string_demo();
    vector_demo();

    return 0;
}

