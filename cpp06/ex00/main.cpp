#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    std::string literal;
    
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else 
        std::cout << "Only one argument allowed!" << std::endl;

    return 0;
}

    // char b = 'F';
    // std::string i = "123456";
    // std::string ii = "123d";
    
    // std::string d = "123456789";
    // std::string dd = "123456789";
    
    // std::string f = "10.123456789";
    // std::string ff = "10.123456789f";

    // std::cout << "valid int: " << std::atoi(i.c_str()) << std::endl;
    // std::cout << "invalid int: " << std::atoi(ii.c_str()) << std::endl;
    
    // std::cout << "valid double: " << std::atof(dd.c_str()) << std::endl;
    // std::cout << "invalid double: " << std::atof(d.c_str()) << std::endl;
    
    // std::cout << "valid float: " << std::atof(ff.c_str()) << std::endl;
    // std::cout << "invalid float: " << std::atof(f.c_str()) << std::endl;

    // std::cout<< "Float cating: " << std::endl;
    // std::cout<< "Char: " << static_cast<char>(aa) << std::endl;
    // std::cout<< "Int: " << static_cast<int>(aa) << std::endl;
    // std::cout<< "Float: " << static_cast<float>(aa) << std::endl;
    // std::cout<< "Double: " << static_cast<double>(aa) << std::endl;

    // std::cout<< "Float cating: " << std::endl;
    // std::cout<< "Char: " << static_cast<char>(aa) << std::endl;
    // std::cout<< "Int: " << static_cast<int>(aa) << std::endl;
    // std::cout<< "Float: " << static_cast<float>(aa) << std::endl;
    // std::cout<< "Double: " << static_cast<double>(aa) << std::endl;

    // std::cout<< "Float cating: " << std::endl;
    // std::cout<< "Char: " << static_cast<char>(aa) << std::endl;
    // std::cout<< "Int: " << static_cast<int>(aa) << std::endl;
    // std::cout<< "Float: " << static_cast<float>(aa) << std::endl;
    // std::cout<< "Double: " << static_cast<double>(aa) << std::endl;

    // std::cout<< "F char cating: " << std::endl;
    // std::cout<< "Char: " << static_cast<char>(b) << std::endl;
    // std::cout<< "Int: " << static_cast<int>(b) << std::endl;
    // std::cout<< "Float: " << static_cast<float>(b) << std::endl;
    // std::cout<< "Double: " << static_cast<double>(b) << std::endl;
//     return 0;
// }