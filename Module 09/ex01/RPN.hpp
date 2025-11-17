#pragma once
#include <stack>
#include <list>

class RPN {
	std::stack<double, std::list<double> > st;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void rpnCalculator(const std::string& expression);
};