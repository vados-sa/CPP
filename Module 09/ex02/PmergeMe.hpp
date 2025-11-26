#pragma once
#include <vector>
#include <deque>

// Your program must be able to handle at least 3000 different integers.
// implement your algorithm for each container

class PmergeMe {
	std::vector<int> _vector;
	long vector_comp_count;
	void fordJohnson(std::vector<int>& seq, std::size_t elemSize);
	void makePairs(std::vector<int>& seq, std::size_t elemSize);
	void insertPend(std::vector<int>& seq, std::size_t elemSize);

	std::deque<int> _deque;
	long deque_comp_count;
	void fordJohnson(std::deque<int>& seq, std::size_t elemSize);
	void makePairs(std::deque<int>& seq, std::size_t elemSize);
	void insertPend(std::deque<int>& seq, std::size_t elemSize);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseList(char *av[]);

		void SortVector();
		void compCountCheck();

		void SortDeque();
};