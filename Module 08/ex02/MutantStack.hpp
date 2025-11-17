#pragma once
 
#include <deque>
#include <stack>

template < class T, class C = std::deque<T> > 
class MutantStack : public std::stack<T, C> {

	public:
		MutantStack() {}
		MutantStack(const MutantStack& other) : std::stack<T, C>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T, C>::operator=(other);
			}
			return *this;
		}
		~MutantStack() {}

		typedef typename C::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		
		typedef typename C::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		
		typedef typename C::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		
		typedef typename C::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};