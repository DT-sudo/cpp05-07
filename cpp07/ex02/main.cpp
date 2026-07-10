#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    // default constructor: empty array
    Array<int> empty;
    std::cout << "empty array size: " << empty.size() << std::endl;
    try
    {
        empty[0];
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "empty[0] threw an exception as expected" << std::endl;
    }

    // constructor with n: elements default-initialized (like int* a = new int();)
    Array<int> numbers(5);
    std::cout << "\nnumbers size: " << numbers.size() << std::endl;
    std::cout << "default-initialized values:";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << " " << numbers[i];
    std::cout << std::endl;

    // writing through the subscript operator
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = (i + 1) * 10;

    // copy constructor and assignment operator: deep copies
    Array<int> copied(numbers);
    Array<int> assigned;
    assigned = numbers;

    numbers[0] = 999;
    std::cout << "\nafter numbers[0] = 999:" << std::endl;
    std::cout << "numbers[0]  = " << numbers[0] << " (modified)" << std::endl;
    std::cout << "copied[0]   = " << copied[0] << " (unaffected)" << std::endl;
    std::cout << "assigned[0] = " << assigned[0] << " (unaffected)" << std::endl;

    // out-of-bounds access must throw std::exception
    try
    {
        numbers[5];
        std::cout << "ERROR: no exception thrown!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "\nnumbers[5] threw an exception as expected" << std::endl;
    }

    // const array: read through the const subscript operator
    const Array<int> constArray(copied);
    std::cout << "\nconst array read: constArray[1] = " << constArray[1] << std::endl;

    // works with any type
    Array<std::string> words(3);
    words[0] = "template";
    words[1] = "of";
    words[2] = "strings";
    std::cout << "\nstring array:";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << " " << words[i];
    std::cout << std::endl;

    return 0;
}
