#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Base* ptr;
    std::srand(time(NULL)); 

    ptr = generate();
    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}
