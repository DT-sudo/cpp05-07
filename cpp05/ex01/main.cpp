#include "Form.hpp"

int main(void)
{
    Bureaucrat firstB(120, "Dime");
    Bureaucrat secondB(122, "Grag");

    Form firstF("main form", 10, 120);

// valide sign test 
    // firstB.signForm(firstF);

// invalide sign tests
    secondB.signForm(firstF);

// Form constructor tests
// bad form name
    // try
    // {
    //     Form badName("", 10, 21);
    // }
    // catch (Form::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(Form::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // // wrong grade to execute
    // try
    // {
    //     Form bad("", 0, 21);
    // }
    // catch (Form::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(Form::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // try
    // {
    //     Form bad("", 151, 21);
    // }
    // catch (Form::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(Form::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // // wrong grade to signe
    // try
    // {
    //     Form badName("", 10, 0);
    // }
    // catch (Form::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(Form::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // try
    // {
    //     Form badName("", 10, 151);
    // }
    // catch (Form::GradeTooHighException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(Form::GradeTooLowException& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }
    // catch(std::invalid_argument& e)
    // {
    //     std::cerr << "Error: " << e.what();
    // }

    
    return 0;
}