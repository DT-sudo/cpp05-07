#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 5, 25), _target(target)
{
    std::cout << "PresidentialPardon constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    this->_target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardon destructor called." << std::endl;
}
