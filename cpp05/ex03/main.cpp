#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
    Intern someIntern;

// valid form name tests
    std::cout << "=== valid form names ===" << std::endl;

    AForm* shrubbery = someIntern.makeForm("shrubbery creation", "home");
    AForm* robotomy  = someIntern.makeForm("robotomy request", "Bender");
    AForm* pardon    = someIntern.makeForm("presidential pardon", "Marvin");

// invalid form name test
    std::cout << "\n=== invalid form name ===" << std::endl;

    AForm* unknown = someIntern.makeForm("coffee making", "Nobody");

// cleanup
    delete shrubbery;
    delete robotomy;
    delete pardon;
    if (unknown)
        delete unknown;

    return 0;
}
