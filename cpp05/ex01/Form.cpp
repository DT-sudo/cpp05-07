#include "Form.hpp"

std::string Form::getName() const
{
   return _name;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

int Form::getGradeToSigne() const
{
    return _gradeToSign;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() <= _gradeToSign)
        isSigned = 1;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form has\nname:" << obj.getName() <<
    "grade to execute: " << obj.getGradeToExecute()<<
    "grade to signe: " << obj.getGradeToSigne() << 
    "signe status: " << obj.getIsSigned();
    return out;
}

Form::Form(const std::string name, int gExecute, int gSinge) : _name(name), _gradeToExecute(gExecute), _gradeToSign(gSinge)
{
    std::cout << "Form constructor called."<< std::endl;
    isSigned = 0;
    if ( _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (_gradeToExecute > 150)
        throw Form::GradeTooLowException();
    if ( _gradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (_gradeToSign > 150)
        throw Form::GradeTooLowException();
    if (_name.empty())
        throw std::invalid_argument("The name cant be empty!");
}

Form::Form(const Form& other) :  _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign)
{
    this->isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called."<< std::endl;
}

