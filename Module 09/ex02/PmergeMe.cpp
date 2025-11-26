#include "PmergeMe.hpp"
#include <ctype.h>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>

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

	std::cout << "Before: ";
	for (int i = 1; av[i]; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

// VECTOR
void PmergeMe::makePairs(std::vector<int>& seq, std::size_t elemSize) {
	const std::size_t n = seq.size();

	for (std::size_t i = elemSize - 1; i + elemSize < n; i += elemSize * 2) {
		vector_comp_count++;
		if (seq[i] > seq[i + elemSize]) {
			std::size_t left_first = i - (elemSize - 1);
			std::size_t right_first = left_first + elemSize;
			std::swap_ranges(seq.begin() + left_first,
							seq.begin() + left_first + elemSize,
							seq.begin() + right_first);
		}
	}
}

std::vector<std::size_t> PmergeMe::buildJacobsthalOrder(const std::vector<std::size_t>& pendElems) {
	std::vector<std::size_t> order;
	order.reserve(pendElems.size());

	if (pendElems.empty())
		return order;

	size_t prev_jacob = 1;
	size_t curr_jacob = 3;
	size_t last_index = 0;

	while (last_index < pendElems.size()) {
		size_t bound_index = curr_jacob - 2;

		if (bound_index >= pendElems.size())
			bound_index = pendElems.size() - 1;

		for (size_t i = bound_index; ; --i) {
			order.push_back(pendElems[i]);
			if (i == last_index)
				break;
		}
		last_index = bound_index + 1;

		size_t next_jacob = curr_jacob + 2 * prev_jacob;
		prev_jacob = curr_jacob;
		curr_jacob = next_jacob;
	}
	return order;
}

void PmergeMe::insertPend(std::vector<int>& seq, std::size_t elemSize) {
	const std::size_t n = seq.size();
	const std::size_t numElements = n / elemSize;
	const std::size_t numPairs    = numElements / 2;
	const bool   hasOdd      = (numElements % 2 != 0);

	std::vector<std::size_t> mainElems;
	if (numPairs > 0) {
		mainElems.push_back(0);

		for (std::size_t p = 0; p < numPairs; ++p) {
			std::size_t a_idx  = 2 * p + 1;
			mainElems.push_back(a_idx);
		}
	}

	std::vector<std::size_t> pendElems;
	for (std::size_t p = 1; p < numPairs; ++p) {
		std::size_t b_idx = 2 * p;
		pendElems.push_back(b_idx);
	}

	if (hasOdd) {
		std::size_t odd_idx = 2 * numPairs;
		pendElems.push_back(odd_idx);
	}

	// Step 3: insert pend into main using Jacobsthal order
	std::vector<std::size_t> order = buildJacobsthalOrder(pendElems);

	for (std::size_t i = 0; i < order.size(); i++) {
		std::size_t bIdx = order[i];
		int bRep = repOfElem(seq, elemSize, bIdx);

		bool isOddElement = false;
		std::size_t odd_idx = 2 * numPairs;
		if (hasOdd && bIdx == odd_idx)
			isOddElement = true;

		std::size_t insertLimit;
		
		if (!isOddElement) {
			std::size_t aIdx = bIdx + 1;
			std::size_t aPos = 0;
			while (aPos < mainElems.size() && mainElems[aPos] != aIdx)
				++aPos;
			
			if (aPos == mainElems.size()) {
				std::cout << "logic bug" << std::endl;
			}

			insertLimit = aPos;
		} else {
			insertLimit = mainElems.size() - 1;
		}

		std::size_t left = 0;
		std::size_t right = isOddElement ? insertLimit + 1 : insertLimit;
		while (left < right) {
			std::size_t mid = left + (right - left) / 2;
			vector_comp_count++;
			if (repOfElem(seq, elemSize, mainElems[mid]) < bRep) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		mainElems.insert(mainElems.begin() + left, bIdx);
	}

	std::vector<int> newSeq;
	newSeq.reserve(n);

	// reorder all full elements
	for (std::size_t idx = 0; idx < mainElems.size(); ++idx) {
		std::size_t e = mainElems[idx];
		std::size_t start = e * elemSize;
		std::size_t end   = start + elemSize;
		newSeq.insert(newSeq.end(), seq.begin() + start, seq.begin() + end);
	}

	// Append numbers that didn't make a full element
	std::size_t used = numElements * elemSize;
	if (used < n) {
		newSeq.insert(newSeq.end(), seq.begin() + used, seq.end());
	}

	// Replace seq with the new
	seq.swap(newSeq); 
}

void PmergeMe::fordJohnson(std::vector<int>& seq, std::size_t elemSize) {
	if (2 * elemSize > seq.size())
		return ;

	makePairs(seq, elemSize);
	fordJohnson(seq, elemSize * 2);
	insertPend(seq, elemSize);
}

void PmergeMe::SortVector() {
	clock_t start = clock();
	fordJohnson(_vector, 1);
	clock_t end = clock();
	double time_taken = double(end - start) / CLOCKS_PER_SEC;
	printContainer(_vector);
	std::cout << "Time to process a range of " << _vector.size() 
			  << " elements with std::vector : " << std::fixed 
			  << std::setprecision(5) << time_taken << " s" << std::endl;
}

// DEQUE
void PmergeMe::makePairs(std::deque<int>& seq, std::size_t elemSize) {
	const std::size_t n = seq.size();

	for (std::size_t i = elemSize - 1; i + elemSize < n; i += elemSize * 2) {
		deque_comp_count++;
		if (seq[i] > seq[i + elemSize]) {
			std::size_t left_first = i - (elemSize - 1);
			std::size_t right_first = left_first + elemSize;
			std::swap_ranges(seq.begin() + left_first,
							seq.begin() + left_first + elemSize,
							seq.begin() + right_first);
		}
	}
}

std::deque<std::size_t> PmergeMe::buildJacobsthalOrder(const std::deque<std::size_t>& pendElems) {
	std::deque<std::size_t> order;

	if (pendElems.empty())
		return order;

	size_t prev_jacob = 1;
	size_t curr_jacob = 3;
	size_t last_index = 0;

	while (last_index < pendElems.size()) {
		size_t bound_index = curr_jacob - 2;

		if (bound_index >= pendElems.size())
			bound_index = pendElems.size() - 1;

		for (size_t i = bound_index; ; --i) {
			order.push_back(pendElems[i]);
			if (i == last_index)
				break;
		}
		last_index = bound_index + 1;

		size_t next_jacob = curr_jacob + 2 * prev_jacob;
		prev_jacob = curr_jacob;
		curr_jacob = next_jacob;
	}
	return order;
}

void PmergeMe::insertPend(std::deque<int>& seq, std::size_t elemSize) {
	const std::size_t n = seq.size();
	const std::size_t numElements = n / elemSize;
	const std::size_t numPairs    = numElements / 2;
	const bool   hasOdd      = (numElements % 2 != 0);

	std::deque<std::size_t> mainElems;
	if (numPairs > 0) {
		mainElems.push_back(0);

		for (std::size_t p = 0; p < numPairs; ++p) {
			std::size_t a_idx  = 2 * p + 1;
			mainElems.push_back(a_idx);
		}
	}

	std::deque<std::size_t> pendElems;
	for (std::size_t p = 1; p < numPairs; ++p) {
		std::size_t b_idx = 2 * p;
		pendElems.push_back(b_idx);
	}

	if (hasOdd) {
		std::size_t odd_idx = 2 * numPairs;
		pendElems.push_back(odd_idx);
	}

	// Step 3: insert pend into main using Jacobsthal order
	std::deque<std::size_t> order = buildJacobsthalOrder(pendElems);

	for (std::size_t i = 0; i < order.size(); i++) {
		std::size_t bIdx = order[i];
		int bRep = repOfElem(seq, elemSize, bIdx);

		bool isOddElement = false;
		std::size_t odd_idx = 2 * numPairs;
		if (hasOdd && bIdx == odd_idx)
			isOddElement = true;

		std::size_t insertLimit;
		
		if (!isOddElement) {
			std::size_t aIdx = bIdx + 1;
			std::size_t aPos = 0;
			while (aPos < mainElems.size() && mainElems[aPos] != aIdx)
				++aPos;
			
			if (aPos == mainElems.size()) {
				std::cout << "logic bug" << std::endl;
			}

			insertLimit = aPos;
		} else {
			insertLimit = mainElems.size() - 1;
		}

		std::size_t left = 0;
		std::size_t right = isOddElement ? insertLimit + 1 : insertLimit;
		while (left < right) {
			std::size_t mid = left + (right - left) / 2;
			deque_comp_count++;
			if (repOfElem(seq, elemSize, mainElems[mid]) < bRep) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		mainElems.insert(mainElems.begin() + left, bIdx);
	}

	std::deque<int> newSeq;

	// reorder all full elements
	for (std::size_t idx = 0; idx < mainElems.size(); ++idx) {
		std::size_t e = mainElems[idx];
		std::size_t start = e * elemSize;
		std::size_t end   = start + elemSize;
		newSeq.insert(newSeq.end(), seq.begin() + start, seq.begin() + end);
	}

	// Append numbers that didn't make a full element
	std::size_t used = numElements * elemSize;
	if (used < n) {
		newSeq.insert(newSeq.end(), seq.begin() + used, seq.end());
	}

	// Replace seq with the new
	seq.swap(newSeq); 
}

void PmergeMe::fordJohnson(std::deque<int>& seq, std::size_t elemSize) {
	if (2 * elemSize > seq.size())
		return ;

	makePairs(seq, elemSize);
	fordJohnson(seq, elemSize * 2);
	insertPend(seq, elemSize);
}

void PmergeMe::SortDeque() {
	clock_t start = clock();
	fordJohnson(_deque, 1);
	clock_t end = clock();
	double time_taken = double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _deque.size() 
			  << " elements with std::deque : " << std::fixed 
			  << std::setprecision(5) << time_taken << " s" << std::endl;
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
	std::cout << "(Deque) Total Comparisions = " << deque_comp_count << std::endl;
}
