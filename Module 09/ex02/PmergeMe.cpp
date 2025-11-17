#include "PmergeMe.hpp"
#include <iostream>
#include <ctype.h>
#include <sstream>

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
		const char *s = av[i];
		if (*s == '+') ++s;
		if (!*s) throw std::runtime_error("Not a positive integer");

		if (*s == '0' && s[1] == '\0')
			throw std::runtime_error("Not a positive integer");
		
		for (const char *p = s; *p; ++p) {
			if (!isdigit(static_cast<unsigned char>(*p)))
				throw std::runtime_error("Not a positive integer");
		}

		unsigned long n = std::strtoul(av[i], 0, 10);
		if (n > INT32_MAX)
			throw std::runtime_error("Integer overflow");
		
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

void PmergeMe::fj_sort_vector() {

/* 	std::cout << _vector.size() << std::endl;
	for (size_t i = 0; i < _vector.size(); i++) {
		std::cout << _vector.at(i) << " ";
	}
	std::cout << std::endl; */
}

/* void PmergeMe::fj_sort_deque() {

} */
