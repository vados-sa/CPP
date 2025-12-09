#include "PmergeMe.hpp"
#include <iostream>

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
		obj.SortDeque();
		//obj.compCountCheck();
		//obj.isSorted();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return 0;
}