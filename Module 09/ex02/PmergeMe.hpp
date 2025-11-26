#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <iomanip>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parseList(char *av[]);

		void SortVector();
		void SortDeque();
		
		void compCountCheck();
	
	private:
		std::vector<int> _vector;
		long vector_comp_count;
		void fordJohnson(std::vector<int>& seq, std::size_t elemSize);
		void makePairs(std::vector<int>& seq, std::size_t elemSize);
		void insertPend(std::vector<int>& seq, std::size_t elemSize);
		std::vector<std::size_t> buildJacobsthalOrder(const std::vector<std::size_t>& pendElems);

		std::deque<int> _deque;
		long deque_comp_count;
		void fordJohnson(std::deque<int>& seq, std::size_t elemSize);
		void makePairs(std::deque<int>& seq, std::size_t elemSize);
		void insertPend(std::deque<int>& seq, std::size_t elemSize);
		std::deque<std::size_t> buildJacobsthalOrder(const std::deque<std::size_t>& pendElems);

		template <typename T> void printContainer(const T& v) {
			std::cout << "After: ";
			for (std::size_t i = 0; i < v.size(); i++) {
				std::cout << v[i] << " ";
			}
			std::cout << std::endl;
		}

		template <typename T> int repOfElem(const T& seq, std::size_t elemSize, std::size_t elemIndex) {
			std::size_t last = elemIndex * elemSize + (elemSize - 1);
			return seq[last];
		}
};