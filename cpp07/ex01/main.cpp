#include "iter.hpp"

void printI(int& i)
{
    std::cout << i << std::endl;
}

void printIc(const int& i)
{
    std::cout << i << std::endl;
}

void printC(char& i)
{
    std::cout << i << std::endl;
}

void printS(std::string& i)
{
    std::cout << i << std::endl;
}

int main(void)
{
    int listInts1[5] = {1,2,3,4,5};
    const int listInts2[5] = {1,2,3,4,5};
    char listChars1[5] = {'1','2','3','4','5'};
    std::string liststrings[5] = {"a","b","c","d","e",};

    ::iter(listInts1, 5, printI);
    std::cout << "\n";
    ::iter(listInts2, 5, printIc);
    std::cout << "\n";
    ::iter(listChars1, 5, printC);
    std::cout << "\n";
    ::iter(liststrings, 5, printS);

    return 0;
}

