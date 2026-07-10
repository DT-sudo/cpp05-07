#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
    private:
    T* _list;
    unsigned int _length;

    public:
    unsigned int size() const
    {
        return _length;
    };

    Array() : _list(NULL), _length(0)
    {
    };

    Array(const unsigned int n)
    {
        _list = new T[n]();
        _length = n;
    }

    Array(const Array& other)
    {
        this->_list = new T[other._length]();
        this->_length = other._length;
        for (unsigned int i = 0; i < _length ; i++)
        {
            this->_list[i]=other._list[i];
        }
    };

    Array& operator=(const Array& other)
    {
        if (&other != this)
        {
            delete[] this->_list;
            this->_list = new T[other._length]();
            this->_length = other._length;
            for (unsigned int i = 0; i < _length; i++)
            {
                this->_list[i] = other._list[i];
            }
        }
        return *this;
    };

    T& operator[](unsigned int i)
    {
        if (i >= _length)
            throw std::exception();
        return _list[i];
    };

    const T& operator[](unsigned int i) const
    {
        if (i >= _length)
            throw std::exception();
        return _list[i];
    };

    ~Array()
    {
        delete[] _list;
    };
};

#endif