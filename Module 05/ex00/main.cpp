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

	// too low
	try {
		Bureaucrat b("Patrick", 151);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	// valid
	try {
		Bureaucrat b("Sindy", 1);
		b.decrementGrade();
		b.incrementGrade();
		std::cout << b;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}

	return 0;
}