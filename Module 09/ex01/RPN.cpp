#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) :st(other.st) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		st = other.st;
	return *this;
}

RPN::~RPN() {}

static bool parseChar(char c) {
	if (!isdigit(c) && c != ' ' &&  c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}

void RPN::rpnCalculator(std::string& expression) {
	for (size_t i = 0; i < expression.size(); i++) {
		if (parseChar(expression[i]) == false)
			throw std::runtime_error(std::string("Invalid token: ") + expression[i]);
		// push char in stack
	}
}
