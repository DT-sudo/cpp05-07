#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    // --- ShrubberyCreationForm (sign 145, exec 137) ---
    std::cout << "=== ShrubberyCreationForm ===" << std::endl;

    ShrubberyCreationForm shrubbery("home");
    Bureaucrat shrubSigner(145, "Alice");
    Bureaucrat shrubExecutor(137, "Bob");
    Bureaucrat shrubWeak(146, "Weak");

    shrubWeak.signForm(shrubbery);       // fail: grade too low to sign
    shrubExecutor.executeForm(shrubbery); // fail: not signed yet
    shrubSigner.signForm(shrubbery);      // success
    shrubExecutor.executeForm(shrubbery); // success

    // --- RobotomyRequestForm (sign 72, exec 45) ---
    std::cout << "\n=== RobotomyRequestForm ===" << std::endl;

    RobotomyRequestForm robotomy("Bender");
    Bureaucrat robotSigner(72, "Carol");
    Bureaucrat robotExecutor(45, "Dave");
    Bureaucrat robotWeak(46, "Weak");

    robotSigner.signForm(robotomy);       // success
    robotWeak.executeForm(robotomy);      // fail: grade too low to execute
    robotExecutor.executeForm(robotomy);  // success (random 50%)
    robotExecutor.executeForm(robotomy);  // success (random 50%)

    // --- PresidentialPardonForm (sign 25, exec 5) ---
    std::cout << "\n=== PresidentialPardonForm ===" << std::endl;

    PresidentialPardonForm pardon("Marvin");
    Bureaucrat pardonSigner(25, "Eve");
    Bureaucrat pardonExecutor(5, "Zaphod");
    Bureaucrat pardonWeak(26, "Weak");

    pardonWeak.signForm(pardon);          // fail: grade too low to sign
    pardonExecutor.executeForm(pardon);   // fail: not signed yet
    pardonSigner.signForm(pardon);        // success
    pardonExecutor.executeForm(pardon);   // success

    return 0;
}
