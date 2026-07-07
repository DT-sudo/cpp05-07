#include "Intern.hpp"

static AForm* createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createPresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);
}

Intern::Intern() : formNames{"shrubbery creation", "presidential pardon", "robotomy request"}
{
    funcPointer[0] = &createShrubbery;
    funcPointer[1] = &createPresidentialPardon;
    funcPointer[2] = &createRobotomyRequest;
}

AForm* Intern::makeForm(std::string _name, std::string _target)
{
    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (formNames[i] == _name)
            {
                std::cout << "Intern creates " << _name << std::endl;
                return funcPointer[i](_target);
            }
        }
        throw std::invalid_argument("The name of the passed form is invalid!");
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}


