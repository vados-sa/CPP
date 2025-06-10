#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "Copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
		return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor" << std::endl;
}

/* IT'S WAY BIGGER THAN I THOUGHT


- detect the type pf the literal passed;
- convert to its actual type;
- convert to the other three data types;
- display the results (char, int, float, double)*/

void ScalarConverter::convert(std::string str)
{
	// char
	char c = 0;
	if (str.length() == 1)
		c = static_cast<char>(str[0]);
	else if ((str[0] == '+' || str[0] == '-') && str.length() == 2 && std::isdigit(str[1]))
		c = static_cast<char>(str[1]);
	if ((c >= 7 && c <= 13) || (c >= 32 && c <= 126))
	std::cout << "char: " << c << std::endl;
	else
	std::cout << "Non displayable" << std::endl;
	
	// int
	int int_value;
	if (str.length() == 1 && !std::isdigit(str[0]))
		int_value = static_cast<int>(str[0]); // gets ascii value
	else
		std::stringstream(str) >> int_value;
	std::cout << "int: " << int_value << std::endl;
	
	
	// float
	float float_value;
	if (str.length() == 1 && !std::isdigit(str[0]))
		float_value = static_cast<float>(str[0]); // gets ascii value
	else
		std::stringstream(str) >> float_value;
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_value << "f" << std::endl;
	
	// double
	double double_value;
	if (str.length() == 1 && !std::isdigit(str[0]))
		double_value = static_cast<double>(str[0]); // gets ascii value
	else
		std::stringstream(str) >> double_value;
	std::cout << "double: " << std::setprecision(1) << double_value << std::endl;
}

