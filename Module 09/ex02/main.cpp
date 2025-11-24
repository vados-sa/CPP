#include "PmergeMe.hpp"
#include <iostream>

// Your program must be able to use a positive integer sequence as an argument.
// Your program must use the merge-insert sort algorithm to sort the positive integer sequence.
// If an error occurs during program execution, an error message should be displayed on the standard error.

/*
Build two containers with the same data (pick two distinct STL containers).
Sort both using the same Ford–Johnson algorithm (not std::sort).
Print “Before:” (original), “After:” (sorted).
Measure and print time for each container (same machine, same input). */


int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cerr << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe obj;
		obj.parseList(av);
		obj.SortVector();
		//obj.SortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return 0;
}