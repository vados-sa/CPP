#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    // without signing
    try
    {
        Bureaucrat b("Bureaucrat", 30);
        ShrubberyCreationForm shrubberyForm(b.getName());

        b.executeForm(shrubberyForm);

        b.signForm(shrubberyForm);
        b.executeForm(shrubberyForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    // success
    try
    {
        Bureaucrat b("Bureaucrat", 30);
        RobotomyRequestForm robotomyForm(b.getName());

        b.signForm(robotomyForm);
        b.executeForm(robotomyForm);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    // grade too low
    try
    {
        Bureaucrat b("Bureaucrat", 30);
        PresidentialPardonForm presidentialForm(b.getName());

        b.signForm(presidentialForm);
        b.executeForm(presidentialForm);

        b.setGrade(5);
        b.signForm(presidentialForm);
        b.executeForm(presidentialForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}