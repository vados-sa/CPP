#include "ScalarConverter.hpp"

/* static_cast<new_type>(exp); */

void ScalarConverter::convert(std::string str)
{
	int int_value;
	std::stringstream(str) >> int_value;

	char c =  static_cast<char>(int_value);
	std::cout << "String as char: " << c << std::endl;
	/* if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	else
		std::cout << "A conversion to char is not displayable." << std::endl; */

	std::cout << "String as int: " << int_value << std::endl;
	
	std::cout << "String as float: " << static_cast<float>(int_value) << std::endl;
	
	std::cout << "String as double: " << static_cast<double>(int_value) << std::endl;

}

