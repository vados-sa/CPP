#include "Fixed.hpp"

void test_comparision(void)
{
	Fixed a(10);
	Fixed b(5);

	if (a > b)
	    std::cout << "a is greater than b" << std::endl;
	
	if (a < b)
	    std::cout << "a is smaller than b" << std::endl;
	
	if (a >= b)
	    std::cout << "a is greater equal b" << std::endl;

	if (a <= b)
	    std::cout << "a is smaller equal b" << std::endl;

	if (a == b)
	    std::cout << "a is equal b" << std::endl;

	if (a != b)
	    std::cout << "a is different than b" << std::endl;
}

void test_arithmetic(void)
{
	Fixed a(10);
	Fixed b(5);

	std::cout << "Addition: " << a + b << std::endl;
	std::cout << "Subtraction: " << a - b << std::endl;
	std::cout << "Multiplication: " << a * b << std::endl;
	std::cout << "Division: " << a / b << std::endl;
}

void test_increment_decrement(void)
{
	Fixed a;

	std::cout << a << std::endl;
	
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << --a << std::endl;
	std::cout << a << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
}

void test_min_max(void)
{
	
}