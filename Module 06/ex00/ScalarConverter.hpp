#pragma once

#include <string>
#include <iostream>
#include <sstream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);

	public:
		ScalarConverter& operator = (const ScalarConverter& other);
		~ScalarConverter(); // or make it virtual
		
		static void convert(std::string str);
		
};