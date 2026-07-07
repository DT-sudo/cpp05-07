#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned() || executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "'some DRILLing noises'" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 45, 72), _target(target)
{
    std::cout << "RobotomyRequest constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequest destructor called." << std::endl;
}
