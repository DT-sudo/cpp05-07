#include "whatever.hpp"

int main(void)
{   

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;

    // int a = 1;
    // int aa = 2;
    // float b = 12.2121;
    // float bb = 31.22;
    // char c = '1';
    // char cc = '2';
    
    // int a1 = 1;
    // int aa1 = 2;
    // float b1 = 31.22;
    // float bb1 = 31.22;
    // char c1 = '1';
    // char cc1 = '0';


    // // swap func check
    // std::cout << "--Swap func test--\nOriginal values before swap:" << std::endl;
    // std::cout << "a = " << a << std::endl;
    // std::cout << "aa = " << aa << std::endl;

    // std::cout << "b = " << b << std::endl;
    // std::cout << "bb = " << bb << std::endl;

    // std::cout << "c = " << c << std::endl;
    // std::cout << "cc = " << cc << "\n"<< std::endl;

    // ::swap(a, aa);
    // ::swap(b, bb);
    // ::swap(c, cc);

    // std::cout << "Values after swap:" << std::endl;
    // std::cout << "a == " << a << std::endl;
    // std::cout << "aa == " << aa << std::endl;
    // std::cout << "b == " << b << std::endl;
    // std::cout << "bb == " << bb << std::endl;
    // std::cout << "c == " << c << std::endl;
    // std::cout << "cc == " << cc << "\n" << std::endl;

    // std::cout << "--Max/Min func test--\nOriginal values:" << std::endl;

    // std::cout << "a1 == " << a1 << std::endl;
    // std::cout << "aa1 == " << aa1 << std::endl;
    // std::cout << "b1 == " << b1 << std::endl;
    // std::cout << "bb1 == " << bb1 << std::endl;
    // std::cout << "c1 == " << c1 << std::endl;
    // std::cout << "cc1 == " << cc1 << "\n"<< std::endl;

    // std::cout << "Max values:" << std::endl;

    // std::cout << "max(a1, aa1): " << ::max(a1, aa1) << std::endl;
    // std::cout << "max(b1, bb1): " << ::max(b1, bb1) << std::endl;
    // std::cout << "max(c1, cc1): " << ::max(c1, cc1) << "\n" << std::endl;

    // std::cout << "--Min func test--\nOriginal values:" << std::endl;

    // std::cout << "Min values:" << std::endl;

    // std::cout << "min(a1, aa1): " << ::min(a1, aa1) << std::endl;
    // std::cout << "min(b1, bb1): " << ::min(b1, bb1) << std::endl;
    // std::cout << "min(c1, cc1): " << ::min(c1, cc1) << "\n" << std::endl;

    // return 0;
}