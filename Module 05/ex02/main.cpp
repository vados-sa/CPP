#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// Test valid form creation and signing
    try {
        Bureaucrat alice("Alice", 42);
        Form taxForm("TaxForm", false, 50, 100);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm); // Should succeed
        std::cout << "Form signed status: " << taxForm.getSign() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---\n" << std::endl;

    // Test signing with too low grade
    try {
        Bureaucrat bob("Bob", 120);
        Form secretForm("SecretForm", false, 50, 100);

        std::cout << bob << std::endl;
        std::cout << secretForm << std::endl;

        bob.signForm(secretForm); // Should fail
        std::cout << "Form signed status: " << secretForm.getSign() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---\n" << std::endl;

    // Test invalid form creation (grade too high)
    try {
        Form badForm("BadForm", false, 0, 100);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test invalid form creation (grade too low)
    try {
        Form badForm2("BadForm2", false, 151, 100);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}