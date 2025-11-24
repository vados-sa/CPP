#include "PmergeMe.hpp"
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <algorithm>
#include <cmath>

PmergeMe::PmergeMe() : vector_comp_count(0), deque_comp_count(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) 
:_vector(other._vector), vector_comp_count(other.vector_comp_count),
_deque(other._deque), deque_comp_count(other.deque_comp_count) {}

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

/* 		if (*s == '0' && s[1] == '\0')
			throw std::runtime_error("Not a positive integer"); */
		
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

static void printVector(std::vector<int>& v) {
	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

/* Loop over pairs of elements and swap entire elemSize blocks when
 the rightmost numbers are out of order. */
void PmergeMe::step1_pair_sort(std::vector<int>& seq, std::size_t elemSize) {
	const std::size_t n = seq.size();

	if (2 * elemSize > n)
		return ;

	for (std::size_t i = elemSize - 1; i + elemSize < n; i += elemSize * 2) {
		if (seq[i] > seq[i + elemSize]) {
			vector_comp_count++;
			std::size_t left_first = i - (elemSize - 1);
			std::size_t right_first = left_first + elemSize;
			std::swap_ranges(seq.begin() + left_first,
							seq.begin() + left_first + elemSize,
							seq.begin() + right_first);
		}
	}

	step1_pair_sort(seq, elemSize * 2);
}

void PmergeMe::SortVector() {
	step1_pair_sort(_vector, 1);
	printVector(_vector);
}

static size_t F(size_t n) {
	size_t sum = 0;

	for (size_t k = 1; k <= n; k++) {
		double value = (3.0/4.0) * k;
		sum += static_cast<size_t>(ceil(log2(value)));
	}
	return sum;
}

void PmergeMe::compCountCheck() {
	size_t n = _vector.size();
	size_t max_allowed = F(n);

	std::cout << "Maximum Comparisions allowed: F(" << n << ") = " << max_allowed << std::endl;
	std::cout << "(Vector) Total Comparisions = " << vector_comp_count << std::endl;
	//std::cout << "(Deqque) Total Comparisions = " << deque_comp_count << std::endl;
}
