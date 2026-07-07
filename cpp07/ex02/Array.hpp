#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
    private:
    T* _list;
    unsigned int length;

    public:
    unsigned int size() const
    {
        return length;
    };

    Array() : _list(NULL), length(0)
    {
    };

    Array(const unsigned int n)
    {
        _list = new T[n]();
        length = n;
    }

    Array(const Array& other)
    {
        this->_list = new T[other.length]();
        this->length = other.length;
        for (unsigned int i = 0; i < length ; i++)
        {
            this->_list[i]=other._list[i];
        }
    };

    Array& operator=(const Array& other)
    {
        if (&other != this)
        {
            delete[] this->_list;
            this->_list = new T[other.length]();
            this->length = other.length;
            for (unsigned int i = 0; i < length; i++)
            {
                this->_list[i] = other._list[i];
            }
        }
        return *this;
    };

    T& operator[](unsigned int i)
    {
        if (i > length-1 && length >= 1)
            throw std::exception();
        else 
            return _list[i];
    };
    
    ~Array()
    {
        delete[] _list;
    };
};

#endif