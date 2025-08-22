#ifndef _MAX_HPP
#define _MAX_HPP

template <typename T>
T max(T a, T b)
{
    if(a > b)
        return a;
    return b;
}

#endif      // _MAX_HPP
