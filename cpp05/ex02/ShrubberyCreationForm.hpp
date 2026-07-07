#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;

    public:
    void execute(Bureaucrat const & executor) const;

    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
};

#endif