#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("Donatelo", 42);
	Bureaucrat b2("Leonardo", 151);
	Bureaucrat b3("Raphael", 0);
	Bureaucrat b4("Michelangelo", 42);

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;
	
	b1.incrementGrade();
	b2.decrementGrade();
	b3.incrementGrade();
	b4.decrementGrade();

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;
	std::cout << b4;

	return 0;
}