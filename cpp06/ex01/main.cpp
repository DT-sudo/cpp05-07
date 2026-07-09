#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    uintptr_t raw;
    Data* ptrBefore;
    Data* ptrAfter;

    data.num = 42;
    data.name = "structName";

    ptrBefore = &data;
    raw = Serializer::serialize(ptrBefore);
    ptrAfter = Serializer::deserialize(raw);

    std::cout << "original pointer:     " << ptrBefore << std::endl;
    std::cout << "serialized value:     " << raw << std::endl;
    std::cout << "deserialized pointer: " << ptrAfter << '\n' << std::endl;

    if (ptrBefore == ptrAfter)
        std::cout << "OK: deserialized pointer compares equal to the original" << std::endl;
    else
        std::cout << "KO: pointers differ!" << std::endl;

    std::cout << "num:  " << ptrAfter->num << std::endl;
    std::cout << "name: " << ptrAfter->name << std::endl;

    return 0;
}
