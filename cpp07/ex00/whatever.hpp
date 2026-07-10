#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename V>
void swap( V& v1, V& v2 )
{
    V v3 = v1;
    v1 = v2;
    v2 = v3;
}

template <typename V>
V max( V v1, V v2)
{
    if( v1 < v2 )
        return v2;
    else if ( v1 > v2 )
        return v1;
    else 
        return v2;
}

template <typename V>
V min( V v1, V v2)
{
    if( v1 > v2 )
        return v2;
    else if ( v1 < v2 )
        return v1;
    else 
        return v2;
}

#endif