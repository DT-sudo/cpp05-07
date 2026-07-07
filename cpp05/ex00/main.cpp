#include "Bureaucrat.hpp"

int main(void)
{

// try catch outOfScope tests
    // try 
    // {
    //     Bureaucrat a(12, "");
    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    
    // try 
    // {
    //     Bureaucrat b(0, "Boby");
    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    
    // try 
    // {
    //     Bureaucrat b(151, "Boby");
    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }

    // try
    // {
    //     Bureaucrat noErrorObject(150, "Sam");
    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    
// incrementation and decrementation tests

    // try
    // {
    //     Bureaucrat noErrorObject2(150, "Greg");
    //     noErrorObject2.decrementGrade();
    //     std::cout << "The grade after decremention: " << noErrorObject2.getGrade() << std::endl;
    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }

    // try
    // {
    //     Bureaucrat noErrorObject3(1, "Lois");
    //     noErrorObject3.incrementGrade();
    //     std::cout << "The grade after decremention: " << noErrorObject3.getGrade() << std::endl;

    // }
    // catch (Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }

// no errors tests
    Bureaucrat noErrorObject4(150, "Greg");
    try
    {
        noErrorObject4.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Error: " << e.what();
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Error: " << e.what();
    }

// overwrite operator << test 
    std::cout << noErrorObject4 << std::endl;

    return 0;
}