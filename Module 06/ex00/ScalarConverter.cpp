#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <limits>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cerrno>

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructor." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << "Copy constructor." << std::endl;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& other)
{
	(void)other;
	std::cout << "Copy assignment operator." << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor" << std::endl;
}

bool isChar(const std::string& s) {
	if (s.empty()) return false;
	
	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))  return true;
	else return false;
}

bool isInt(const std::string& s) {
	if (s.empty()) return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		if (s.size() == 1) return false;
		i++;
	}
	for (; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
	return true;
}

bool isFloat(const std::string& s) {
	if (s.empty() || s[s.size() - 1] != 'f') return false;

	std::string num = s.substr(0, s.size()-1);
    if (num.empty()) return false;
	
	size_t i = 0;
	if (num[i] == '+' || num[i] == '-') {
		if (num.size() == 1) return false;
		i++;
	}

	bool hasDot = false;
	for (; i < num.size(); i++) {
        if (num[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(static_cast<unsigned char>(num[i]))) {
            return false;
        }
	}
	return hasDot;
}

bool isDouble(const std::string& s) {
	if (s.empty()) return false;
	
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		if (s.size() == 1) return false;
		i++;
	}

	bool hasDot = false;
	for (; i < s.size(); i++) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(static_cast<unsigned char>(s[i]))) {
            return false;
        }
	}
	return hasDot;
}

bool isPseudoLit(const std::string& s) {
    return (s == "nan" || s == "nanf" || 
            s == "+inf" || s == "-inf" || 
            s == "+inff" || s == "-inff");
}

void convertFromChar(const std::string& s) {
	char c = s[0];
	
	if (std::isprint(c)) std::cout << "char: " << c << std::endl;
	else std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0"  << std::endl;
}

void convertFromInt(const std::string& s) {
	char* endptr = 0;
	errno = 0;
	bool valid = true;

	long v = strtol(s.c_str(), &endptr, 10);
	if ((!endptr || *endptr != '\0') || // X parsed the whole string
		(errno == ERANGE) || // outside long's range
		(v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())) valid = false;

	if (valid) {
		int n = static_cast<int>(v);
		int cmin = std::numeric_limits<char>::min();
		int cmax = std::numeric_limits<char>::max();
		if (n >= cmin && n <= cmax) {
			char c = static_cast<char>(n);
			if (std::isprint(c)) std::cout << "char: " << c << std::endl;
			else std::cout << "char: Non displayable" << std::endl; 
	
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << ".0"  << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

void convertFromFloat(const std::string& s) {
	char* endptr = 0;
	errno = 0;
	bool valid = true;
	
	std::string num = s.substr(0, s.size()-1);
    if (num.empty()) valid = false;

	double v = strtod(num.c_str(), &endptr);
	if ((!endptr || *endptr != '\0') || // didn't parsed the whole string
		(errno == ERANGE) || // outside long's range
		(v < -std::numeric_limits<float>::max() || v > std::numeric_limits<float>::max())) valid = false;
	
	if (valid) {
		float f = static_cast<float>(v);
		int cmin = std::numeric_limits<char>::min();
		int cmax = std::numeric_limits<char>::max();
		if (f >= cmin && f <= cmax) {
			char c = static_cast<char>(f);
			if (std::isprint(static_cast<unsigned char>(c))) std::cout << "char: " << c << std::endl;
			else std::cout << "char: Non displayable" << std::endl; 
	
		}
		else
			std::cout << "char: impossible" << std::endl;

		if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else	std::cout << "int: " << static_cast<int>(f) << std::endl;

		if (std::floor(f) == f)	std::cout << "float: " << f << ".0f" << std::endl;
		else	std::cout << "float: " << f << "f" << std::endl;

		double d = static_cast<double>(f);
		if (std::floor(d) == d) std::cout << "double: " << d << ".0" << std::endl;
		else std::cout << "double: " << d << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

void convertFromDouble(const std::string& s) {
	char* endptr = 0;
	errno = 0;
	bool valid = true;

	double d = strtod(s.c_str(), &endptr);
	if ((!endptr || *endptr != '\0') || (errno == ERANGE)) valid = false;
	
	if (valid) {
		int cmin = std::numeric_limits<char>::min();
		int cmax = std::numeric_limits<char>::max();
		if (d >= cmin && d <= cmax)  {
			char c = static_cast<char>(d);
			if (std::isprint(c)) std::cout << "char: " << c << std::endl;
			else std::cout << "char: Non displayable" << std::endl; 
	
		}
		else	std::cout << "char: impossible" << std::endl;

		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else	std::cout << "int: " << static_cast<int>(d) << std::endl;

		if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else {
			float f = static_cast<float>(d);
			if (std::floor(f) == f)
			    std::cout << "float: " << f << ".0f" << std::endl;
			else
			    std::cout << "float: " << f << "f" << std::endl;
		}
		if (std::floor(d) == d) std::cout << "double: " << d << ".0"  << std::endl;
		else std::cout << "double: " << d  << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}

void convertFromPseudoLit(const std::string& s) {
	std::string	pseudoLit[] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};

	std::cout << "char: impossible\nint: impossible" << std::endl;
	int i = 0;
	while(i < 6)
	{
		if (pseudoLit[i] == s)
			break ;
		i++;
	}
	
	switch (i)
	{
		case 0: case 1:
			std::cout << "float: nanf\ndouble: nan" << std::endl;
			break;
		case 2: case 3:
			std::cout << "float: +inff\ndouble: +inf" << std::endl;
			break;
		case 4: case 5:
			std::cout << "float: -inff\ndouble: -inf" << std::endl;
			break;
		default:
        std::cout << "float: impossible\ndouble: impossible" << std::endl;
        break;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (isChar(str)) convertFromChar(str);
	
	else if (isInt(str)) convertFromInt(str);
	
	else if (isFloat(str)) convertFromFloat(str);
	
	else if (isDouble(str))	convertFromDouble(str);
	
	else if (isPseudoLit(str)) {
		convertFromPseudoLit(str);
	}
	else
		std::cout << "char: impossible\n\
					  int: impossible\n\
					  float: impossible\n\
					  double: impossible" << std::endl;
}

