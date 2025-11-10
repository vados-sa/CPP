#include "PmergeMe.hpp"
#include <iostream>

// Your program must be able to use a positive integer sequence as an argument.
// Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
// If an error occurs during program execution, an error message should be displayed on the standard error.


int main(int ac, char *av[]) {
	if (ac == 1)
		return 1;

	try
	{
		PmergeMe obj;
		obj.parseList(av);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
}