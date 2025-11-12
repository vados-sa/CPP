#include "PmergeMe.hpp"
#include <iostream>
#include <ctype.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
:_vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other){
		_vector = other._vector;
		_deque = other._deque;
	} 
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseList(char *av[]) {
	
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]) || av[i][j] == '0') // should I take care of '+'?
				throw std::runtime_error(std::string("Not a positive integer"));
		}

		float n = atol(av[i]);
		if (n > INT32_MAX)
			throw std::runtime_error(std::string("Integer overflow"));
		
		_vector.push_back(static_cast<int>(n));
		_deque.push_back(static_cast<int>(n));
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
