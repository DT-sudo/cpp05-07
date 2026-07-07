#include "ScalarConverter.hpp"
#include <cerrno>
#include <cctype>
#include <iomanip>

static void printPseudo(std::string literal);
static void isChar(std::string literal);
static void isInt(std::string literal);
static void isFloat(std::string literal);
static void isDouble(std::string literal);
static void printChar(double d);
static void printInt(double d);
static void printFloat(double d);
static void printDouble(double d);
static bool checkOverflow(std::string literal, double& d);

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

static bool isPseudo(std::string literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
    literal == "-inf"  || literal == "+inf"  || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        printPseudo(literal);
        return true;
    }
    return false;
}

static void printPseudo(std::string literal)
{
    if (literal == "+inff" || literal == "-inff" ||
         literal == "+inf" || literal == "-inf")
    {
        if(literal[0] == '-')
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else if (literal[0] == '+')
        {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
    }
    else if (literal == "nanf" || literal == "nan")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    bool dot = 0;
    bool f = 0;
    int length = literal.length();

    // pseudo test
    if (isPseudo(literal))
        return;

    // single char case
    if ( length == 1 && std::isprint(static_cast<unsigned char>(literal[0])) &&
         !std::isdigit(static_cast<unsigned char>(literal[0])) )
    {
        isChar(literal);
        return;
    }
    // signed double / float / int
    else if ( (literal[0] == '-' || literal[0] == '+') && length > 1)
    {
        for ( int i = 1; i < length; i++ )
        {
            if( std::isdigit(static_cast<unsigned char>(literal[i])) )
                continue;
            else if( literal[i] == '.' && literal[1] != '.' && !dot && !(i == length - 1) )
            {
                dot = 1;
                continue;
            }
            else if( literal[i] == 'f' && i == length - 1 && dot &&
                     std::isdigit(static_cast<unsigned char>(literal[i-1])) )
            {
                f = 1;
                continue;
            }
            return;
        }
        if ( f && dot )
            isFloat(literal);
        else if ( dot )
            isDouble(literal);
        else
            isInt(literal);
        return;
    }
    // unsigned double / float / int
    else if( std::isdigit(static_cast<unsigned char>(literal[0])) )
    {
        for ( int i = 0; i < length; i++ )
        {
            if( std::isdigit(static_cast<unsigned char>(literal[i])) )
                continue;
            else if( literal[i] == '.' && !dot && !(i == length - 1) )
            {
                dot = 1;
                continue;
            }
            else if( literal[i] == 'f' && i == length - 1 && dot &&
                     std::isdigit(static_cast<unsigned char>(literal[i-1])) )
            {
                f = 1;
                continue;
            }
            return;
        }
        if ( f && dot )
            isFloat(literal);
        else if ( dot )
            isDouble(literal);
        else
            isInt(literal);
        return;
    }
    
    std::cout << "Invalid input literal" << std::endl;

    return;
}

static void printChar(double d)
{
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1)
                   << static_cast<float>(d) << "f" << std::endl;
}

static void printDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void isChar(std::string literal)
{
    char chr = literal[0];

    printChar(static_cast<double>(chr));
    printInt(static_cast<double>(chr));
    printFloat(static_cast<double>(chr));
    printDouble(static_cast<double>(chr));
}

static void isInt(std::string literal)
{
    double d;
    
    if (!checkOverflow(literal, d))
        return;
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

static void isFloat(std::string literal)
{
    double d;
    
    if (!checkOverflow(literal, d))
        return;
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

static void isDouble(std::string literal)
{
    double d;
    
    if (!checkOverflow(literal, d))
        return;
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

static bool checkOverflow(std::string literal, double& d)
{
    errno = 0;
    d = std::strtod(literal.c_str(), NULL);

    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return false;
    }
    return true;
}