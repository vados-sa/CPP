#pragma once
#include <stack>

class RPN {
	std::stack<int> st;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void rpnCalculator(std::string& expression);
};