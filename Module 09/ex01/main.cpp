#include "RPN.hpp"
#include <iostream>

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	RPN obj;
	std::string expression(av[1]);

	try
	{
		obj.rpnCalculator(expression);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}