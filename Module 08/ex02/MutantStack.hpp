#pragma once
 
#include <deque>
#include <stack>
#include <cstddef>

template < class T, class C = std::deque<T> > 
class MutantStack : public std::stack<T, C> {
	T *elements;
	std::size_t _size;

	public:
		MutantStack() : elements(NULL), _size(0) {};
		MutantStack(const MutantStack& other) : elements(other.elements), _size(other._size){};
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				elements = other.elements;
				_size = other._size;
			}
			return *this;
		};
		~MutantStack() {}

		// iterator = memeber function. point to first and last elements of container
		 // read on other containers iterators
		typedef typename C::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const iterator begin() const { return this->c.begin(); }
		const iterator end() const { return this->c.end(); }

};