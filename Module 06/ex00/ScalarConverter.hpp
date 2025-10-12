#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip> 

class ScalarConverter {
	private:
	
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator = (const ScalarConverter& other);
		virtual ~ScalarConverter();
		
		static void convert(std::string str);
		
};