#ifndef BUREAUCRAT_HPP
#define  BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
class AForm;

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;
    
    public:

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw() 
        {
            return "Grade is too high! Grade should be bigger than 0\n";
        }
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw()
        {
            return "Grade is too law! Grade should be less than 151\n";
        }
    };

    void signForm(AForm& form);

    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;

    void executeForm(AForm const & form) const;

    Bureaucrat(int grade, std::string name);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif 
