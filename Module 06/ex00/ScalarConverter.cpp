#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	int str_int;
	std::stringstream(str) >> str_int;
	std::cout << "String as int: " << str_int << std::endl;
	
	float str_float = 0;
	std::stringstream(str) >> str_float;
	std::cout << "String as float: " << str_float<< std::endl;
	
	double str_double = 0;
	std::stringstream(str) >> str_double;
	std::cout << "String as double: " << str_double<< std::endl;

	if ((str_int >= 65 && str_int <= 90) || (str_int >= 97 && str_int <= 122))
		std::cout << "String as char: " << str_int << std::endl;
	else
		std::cout << "A conversion to char is not displayable." << std::endl;

}

