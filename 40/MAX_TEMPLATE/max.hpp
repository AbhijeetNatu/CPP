#ifndef _MAX_HPP
#define _MAX_HPP


// GENERIC TEMPLATE PROGRAMMING

template <typename T>
T max(T a, T b)
{
    if(a > b)
        return a;
    return b;
}


// TEMPLATE AND TYPENAME both are identifiers


// SCOPE OF THIS IS LIMITED TO CLOSING BRACES OF THE FUNCTION BELOW THIS TEMPLATE
// THIS IS TEMPLATE PARAMETER LIST(line no 21)
template <typename T1, typename T2, typename Tr>
Tr max(T1 a, T2 b)
{
    if(a > b)
        return a;
    return b;
}


#endif      // _MAX_HPP


/*


int max(int a,int b)   // WILL WORK ONLY FOR INT VARIABLES 
{
    if(a>b)
        return a;
    else
        return b;
}

/////////   TYPE COMMITMENT       ////////////

float max(float a , float b)    // WILL WORK ONLY FOR FLOAT VARIABLES 
{
    if(a>b)
        return a;
    else
        return b;
}


*/
