#include "RPN.hpp"
#include <iostream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) :st(other.st) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		st = other.st;
	return *this;
}

RPN::~RPN() {}

void RPN::rpnCalculator(const std::string& expression) {
	while(!st.empty())
    	st.pop();

	if (expression.size() == 0)
		throw std::runtime_error(std::string("Empty expression"));

	for (size_t i = 0; i < expression.size(); i++) {
		if (std::isspace(expression[i])) continue ;
		else if (isdigit(static_cast<unsigned char>(expression[i]))) {
			if (i+1 < expression.size() && std::isdigit(static_cast<unsigned char>(expression[i + 1])))
				throw std::runtime_error(std::string("Only single-digit operands allowed"));
			else if (i+1 < expression.size() && !std::isspace(expression[i + 1]))
				throw std::runtime_error(std::string("Missing space after operand"));
			
			double operand = expression[i] - '0';
			st.push(operand); 
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			if (st.size() < 2)
				throw std::runtime_error(std::string("Not enough operands"));

			char op = expression[i];
			double rightOperand = st.top(); st.pop();
			double leftOperand = st.top(); st.pop();

			if (op == '+')
				st.push(leftOperand + rightOperand);
			else if (op == '-')
				st.push(leftOperand - rightOperand);
			else if (op == '*')
				st.push(leftOperand * rightOperand);
			else {
				if (rightOperand != 0)
					st.push(leftOperand / rightOperand);
				else throw std::runtime_error(std::string("Division by zero"));
			}
		}
		else throw std::runtime_error(std::string("Invalid token: ") + expression[i]);
		
	}

	if (st.size() > 1)
		throw std::runtime_error(std::string("Too many operands"));
	else
		std::cout << st.top() << std::endl;
}
