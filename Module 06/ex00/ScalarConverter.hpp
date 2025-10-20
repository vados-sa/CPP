#pragma once

#include <string>

class ScalarConverter {
	private:
	
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator = (const ScalarConverter& other);
		virtual ~ScalarConverter();
		
		static void convert(std::string str);
		
};