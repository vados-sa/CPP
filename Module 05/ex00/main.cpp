#include "Bureaucrat.hpp"

int main()
{
	// too high
	try {
		Bureaucrat b("Bureaucrat A", 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	// too low
	try {
		Bureaucrat b("Bureaucrat B", 151);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	// valid
	try {
		Bureaucrat b("Bureaucrat C", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}