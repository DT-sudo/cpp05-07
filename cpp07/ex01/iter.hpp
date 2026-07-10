#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename V, typename F >
void iter(V* address, int const length, F f)
{
    if (length == 0)
    {
        std::cout << "Array is empty!" << std::endl;
        return ;
    }
    for (int i = 0 ; i < length; i++)
    {
        f( address[i] );
    }
}

#endif