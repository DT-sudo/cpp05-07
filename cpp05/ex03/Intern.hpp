#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
    std::string formNames[3];
    AForm* (*funcPointer[3])(std::string);

    public:
    AForm* makeForm(std::string _name, std::string _target);

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
};

#endif