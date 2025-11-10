#pragma once
#include <stack>

class RPN {
	std::stack<double> st;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void rpnCalculator(const std::string& expression);
};