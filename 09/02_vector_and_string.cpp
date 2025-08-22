#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void string_demo(void)
{
    string s1;
    string s2("Hello");
    string s3(s2);

    cout << endl << "--------string demo ------------" <<endl;
    cout<< "s1:"  <<  s1 <<endl;
    cout<< "s2:"  <<  s2 <<endl;
    cout<< "s3:"  <<  s3 <<endl;

    cout << "addr(s2):"<<  &s2 << endl;
    cout << "addr(s3):"<<  &s3 << endl;

    cout << "s2 s3  contents  are same.. but  addresses are not.. "<< endl  
        << "this proves s3 is clone  of s2."  <<  endl<< endl; 

    cout << "Show a string char by char:" <<endl;
    cout <<"------------Method 1 :  Using index------------" <<endl;

    for(string::size_type i = 0; i != s2.size(); ++i)
        cout << "s2[" << i << "]:" << s2[i] << endl;

    cout <<"------------Method 1 End ------------" << endl<< endl;

    cout <<"------------Method 2 :  Using Iterator------------"<< endl;

    for(string::iterator iter = s2.begin();iter !=s2.end() ; ++iter)
        cout << "*iter = " << *iter << endl;

    cout <<"------------Method 2 End ------------" << endl;
    
    cout << "------------string demo leave------------" <<endl;
}

void vector_demo(void)
{

}

int  main(void)
{
    string_demo();
    vector_demo();

    return 0;
}