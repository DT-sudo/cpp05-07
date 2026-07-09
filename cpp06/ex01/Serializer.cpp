#include "Serializer.hpp"
#include <cstddef>
#include <iostream>

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize( Data* ptr )
{
    if (ptr != NULL)
        return reinterpret_cast<uintptr_t>(ptr);
    return 0;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    if(raw != 0)
        return reinterpret_cast<Data*>(raw);
    return NULL;
}
