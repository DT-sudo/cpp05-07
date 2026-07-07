#include "Bureaucrat.hpp"
#include "Form.hpp"

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        _grade-=1;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        _grade += 1;
}

void Bureaucrat::signForm(Form& form)
{
    try 
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(Form::GradeTooLowException& e)
    {
        std::cerr << _name << " couldn't sign " << form.getName()
        << " because " << e.what();
    }
}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name), _grade(grade)
{
    std::cout << "Constructore called" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (name.empty())
        throw std::invalid_argument("The name cant be empty!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructore called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructore called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}
