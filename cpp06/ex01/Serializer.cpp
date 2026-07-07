#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer called" << std::endl;
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
