#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
    private:
    const std::string _name;
    const int _gradeToExecute;
    const int _gradeToSign;
    bool isSigned;

    public:
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "The grade is too high!\n";
        }
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "The grade is too low!\n";
        }
    };
    
    std::string getName() const;
    int getGradeToExecute() const;
    int getGradeToSigne() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat& obj);

    virtual void execute(Bureaucrat const & executor) const = 0;

    AForm(const std::string name, int gExecute, int gSign);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif