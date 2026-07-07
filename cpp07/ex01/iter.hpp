#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename V, typename F >
void iter(V* adress, int const lenght, F f)
{
    if (lenght == 0)
    {
        std::cout << "The past array is empty!" << std::endl;
        return ;
    }
    for (int i = 0 ; i < lenght; i++)
    {
        f( adress[i] );
    }
}

#endif