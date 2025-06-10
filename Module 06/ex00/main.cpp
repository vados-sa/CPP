#include "ScalarConverter.hpp"

int main()
{
	std::cout << "Converting a number:" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << std::endl;

	std::cout << "Converting a character:" << std::endl;
	ScalarConverter::convert("A");

	std::cout << std::endl;

	std::cout << "Converting pseudo-literals f:" << std::endl;
	ScalarConverter::convert("+inff");

	std::cout << std::endl;

	std::cout << "Converting pseudo-literals d:" << std::endl;
	ScalarConverter::convert("+inf");
	/* std::cout << "Converting a string:" << std::endl; // not sure if this should be handled
	ScalarConverter::convert("hello"); */
}