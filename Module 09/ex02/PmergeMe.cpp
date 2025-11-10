#include "PmergeMe.hpp"
#include <iostream>
#include <ctype.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
:containerOne(other.containerOne), containerTwo(other.containerTwo) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other){
		containerOne = other.containerOne;
		containerTwo = other.containerTwo;
	} 
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseList(char *av[]) {
	
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]) || av[i][j] == '0')
				throw std::runtime_error(std::string("Not a positive integer"));
		}

		float n = atol(av[i]);
		if (n > INT_MAX)
			throw std::runtime_error(std::string("Integer overflow"));
		
		containerOne.push_back(static_cast<int>(n));
		containerTwo.push_back(static_cast<int>(n));
	}

	std::cout << "Before: "; // double check if this is the best place for this.
	int i = 1;
	while (av[i + 1] && i < 5) {
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << av[i];
	if (av[i + 1])
		std::cout << " [...]";
	std::cout << std::endl;
}
