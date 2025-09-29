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
        Bureaucrat bob("SpongeBob", 70);
        Form pineappleForm("Pineapple Form", 50, 100);

        std::cout << bob;
        std::cout << pineappleForm;

        bob.signForm(pineappleForm);
        std::cout << "Is form signed: " << pineappleForm.getSignBool() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

	// Test valid form creation and signing
    try {
        Bureaucrat Patrick("Patrick", 42);
        Form shellForm("Shell Form", 50, 100);

        std::cout << Patrick;
        std::cout << shellForm;

        Patrick.signForm(shellForm);
        std::cout << "Is form signed: " << shellForm.getSignBool() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}