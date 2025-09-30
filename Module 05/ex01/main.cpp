#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Invalid form creation (grade too high)
    try {
        Form badForm("BadFormHigh", 0, 100);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Invalid form creation (grade too low)
    try {
        Form badForm2("BadFormLow", 151, 100);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test sign with too low grade
    try {
        Bureaucrat b("Bureaucrat A", 70);
        Form form("Form A", 50, 100);

        std::cout << b;
        std::cout << form;

        b.signForm(form);
        std::cout << "Is form signed: " << form.getSignBool() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	// Test valid form creation and signing
    try {
        Bureaucrat b("Bureaucrat B", 42);
        Form form("Form B", 50, 100);

        std::cout << b;
        std::cout << form;

        b.signForm(form);
        std::cout << "Is form signed: " << form.getSignBool() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}