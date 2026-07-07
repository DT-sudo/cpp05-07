#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
// class Bureaucrat;

class Form
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

    Form(const std::string name, int gExecute, int gSign);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif