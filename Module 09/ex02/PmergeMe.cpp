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
static void printVector(const std::vector<int>& v) {
	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

/* static std::vector<int> flattenElems(const std::vector<int>& seq,
                              std::size_t elemSize,
                              const std::vector<std::size_t>& elems)
{
    std::vector<int> out;
	out.reserve(elems.size() * elemSize);

    for (std::vector<std::size_t>::const_iterator it = elems.begin(); it != elems.end(); ++it)
	{
	    std::size_t e = *it;
	    std::size_t start = e * elemSize;
	    std::size_t end   = start + elemSize;
	    out.insert(out.end(), seq.begin() + start, seq.begin() + end);
	}
    return out;
} */

static int repOfElem(const std::vector<int>& seq, std::size_t elemSize, std::size_t elemIndex)
{
    std::size_t last = elemIndex * elemSize + (elemSize - 1);
    return seq[last];
}


static std::vector<std::size_t> buildJacobsthalOrder(const std::vector<std::size_t>& pendElems) {
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

void PmergeMe::fordJohnson(std::vector<int>& seq, std::size_t elemSize) {
	// Step 1
	const std::size_t n = seq.size();

	if (2 * elemSize > n)
		return ;

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

	fordJohnson(seq, elemSize * 2);

	// Step 2: build chains (main + pend)

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


	/* std::cout << "Level elemSize=" << elemSize << "\nMain: ";
	printVector(flattenElems(seq, elemSize, mainElems));
	std::cout << "Pend: ";
	printVector(flattenElems(seq, elemSize, pendElems)); */

	// Step 3: insert pend into main using Jacobsthal order
	std::vector<std::size_t> order = buildJacobsthalOrder(pendElems);

	for (std::size_t i = 0; i < order.size(); i++) { // jacobsthal sequence goes in here.
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

void PmergeMe::SortVector() {
	std::vector<int> tmp = _vector;
	std::sort(tmp.begin(), tmp.end());
	std::cout << "Using std::sort:" << std::endl;
	printVector(tmp);
	std::cout << "Using Ford Johnson:" << std::endl;
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
	//std::cout << "(Deque) Total Comparisions = " << deque_comp_count << std::endl;
}
