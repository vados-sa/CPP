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
		
		_vector.push_back(static_cast<int>(n)); // this can probably be optimized
		_deque.push_back(static_cast<int>(n));
	}

/* 	std::cout << "Before: "; // double check if this is the best place for this.
	int i = 1;
	while (av[i + 1] && i < 5) {
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << av[i];
	if (av[i + 1])
		std::cout << " [...]";
	std::cout << std::endl; */
}

// turn this into a template function to print like the subject.
static void printVector(std::vector<int>& v) {
	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::fordJohnson(std::vector<int>& seq, std::size_t elemSize) {
	// Step 1
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

	fordJohnson(seq, elemSize * 2);

	// Step 2: build chains (main + pend)

	std::vector<int> main;
	std::vector<int> pend;

	const std::size_t numElements = n / elemSize;
	const std::size_t numPairs    = numElements / 2;
	const bool   hasOdd      = (numElements % 2 != 0);

	// MAIN: b1 + all a's
	if (numPairs > 0) {
		// b1 = element 0
		std::size_t b1_start = 0;
		std::size_t b1_end   = elemSize;
		main.insert(main.end(), seq.begin() + b1_start, seq.begin() + b1_end);

		// all a's: element indices 1, 3, 5, ..., 2*numPairs - 1
		for (std::size_t p = 0; p < numPairs; ++p) {
			std::size_t a_idx  = 2 * p + 1;
			std::size_t start  = a_idx * elemSize;
			std::size_t end    = start + elemSize;
			main.insert(main.end(), seq.begin() + start, seq.begin() + end);
		}
	}

	// PEND: b2..b_numPairs
	for (std::size_t p = 1; p < numPairs; ++p) { // start at b2
		std::size_t b_idx = 2 * p;
		std::size_t start = b_idx * elemSize;
		std::size_t end   = start + elemSize;
		pend.insert(pend.end(), seq.begin() + start, seq.begin() + end);
	}

	// plus odd element as full element in pend
	if (hasOdd) {
		std::size_t odd_idx = 2 * numPairs;
		std::size_t start   = odd_idx * elemSize;
		std::size_t end     = start + elemSize;
		pend.insert(pend.end(), seq.begin() + start, seq.begin() + end);
	}


	std::cout << "Level elemSize=" << elemSize << "\nMain: ";
	printVector(main);
	std::cout << "Pend: ";
	printVector(pend);

	// Step 3: insert pend into main using Jacobsthal order
}

void PmergeMe::SortVector() {
	fordJohnson(_vector, 1);
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
