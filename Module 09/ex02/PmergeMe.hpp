#pragma once
#include <vector>
#include <deque>


// use at least two different containers
// Your program must be able to handle at least 3000 different integers.
// implement your algorithm for each container

class PmergeMe {
	std::vector<int> containerOne;
	std::deque<int> containerTwo;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseList(char *av[]);
};