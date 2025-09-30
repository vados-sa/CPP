#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    // subject example
    try
    {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (!rrf) throw std::runtime_error("unknown form");

        Bureaucrat b("Bureaucrat A", 1);

        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    // shrubbery form
    try
    {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

        Bureaucrat b("Bureaucrat B", 1);

        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    // presidential pardon
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");

        Bureaucrat b("Bureaucrat A", 1);

        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

   // unknown form
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("42 form", "Bender");

        Bureaucrat b("Bureaucrat A", 1);

        b.signForm(*rrf);
        b.executeForm(*rrf);
        delete rrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}