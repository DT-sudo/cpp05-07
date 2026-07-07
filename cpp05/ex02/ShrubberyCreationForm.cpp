#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 137, 145), _target(target)
{
    std::cout << "ShrubberyCreation constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned() || executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file(_target + "_shrubbery");
    file << "     ***     \n";
    file << "    *****    \n";
    file << "   *******   \n";
    file << "    *****   \n";
    file << "      |      \n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreation destructor called." << std::endl;
}