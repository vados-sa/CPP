#pragma once
#include <vector>
#include <deque>

// Your program must be able to handle at least 3000 different integers.
// implement your algorithm for each container

class PmergeMe {
	std::vector<int> _vector;
	void fordJohnson(std::vector<int>& seq, std::size_t elemSize);
	long vector_comp_count;

	std::deque<int> _deque;
	long deque_comp_count;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseList(char *av[]);

		void SortVector();
		//size_t get_vector_size() const;
		void compCountCheck();

		//void SortDeque();
};