#include "AForm.hpp"

std::string AForm::getName() const
{
   return _name;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

int AForm::getGradeToSigne() const
{
    return _gradeToSign;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() <= _gradeToSign)
        isSigned = 1;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "AForm has\nname:" << obj.getName() <<
    "grade to execute: " << obj.getGradeToExecute()<<
    "grade to signe: " << obj.getGradeToSigne() << 
    "signe status: " << obj.getIsSigned();
    return out;
}

AForm::AForm(const std::string name, int gExecute, int gSinge) : _name(name), _gradeToExecute(gExecute), _gradeToSign(gSinge)
{
    std::cout << "AForm constructor called."<< std::endl;
    isSigned = 0;
    if ( _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    if ( _gradeToSign < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeToSign > 150)
        throw AForm::GradeTooLowException();
    if (_name.empty())
        throw std::invalid_argument("The name cant be empty!");
}

AForm::AForm(const AForm& other) :  _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign)
{
    this->isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called."<< std::endl;
}
