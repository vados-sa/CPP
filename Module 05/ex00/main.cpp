#include "Bureaucrat.hpp"

int main()
{
	// too high
	try {
		Bureaucrat b("SpongeBob", 0);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	// too low
	try {
		Bureaucrat b("Patrick", 151);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;

	// valid
	try {
		Bureaucrat b("Sindy", 1);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}