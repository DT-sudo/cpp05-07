#include "Serializer.hpp"

int main(void)
{
    Data* ptrToStruct1;
    Data* ptrToStruct2;
    Data newStruct;
    uintptr_t adressInInt;

    ptrToStruct1 = &newStruct;
    newStruct.name = "structName";
    newStruct.num = 42;

    std::string* adressOfName = &newStruct.name;
    int* adressOfNum = &newStruct.num;

    adressInInt = Serializer::serialize(&newStruct);
    ptrToStruct2 = Serializer::deserialize(adressInInt);

    std::cout << newStruct.name << std::endl;
    std::cout << newStruct.num << '\n' << std::endl;

    std::cout << &newStruct.name << " == " << adressOfName << std::endl;
    std::cout << &newStruct.num <<  " == " << adressOfNum  << '\n' << std::endl;
    
    std::cout << ptrToStruct1 <<  " == " << ptrToStruct2 << std::endl;
    
    return 0;
}