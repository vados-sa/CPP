#pragma once
#include <vector>
#include <deque>

// Your program must be able to handle at least 3000 different integers.
// implement your algorithm for each container

class PmergeMe {
	std::vector<int> _vector;
	void step1_pair_sort(std::vector<int>& seq, std::size_t elemSize);

	std::deque<int> _deque;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseList(char *av[]);

		void SortVector();
		//size_t get_vector_size() const;

		//void SortDeque();
};