#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "--- MutantStack ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << std::endl;

	// test with another container
	std::cout << "--- std::list ---" << std::endl;
	std::list<int> liststack;

	liststack.push_back(5);
	liststack.push_back(17);

	std::cout << liststack.back() << std::endl;

	liststack.pop_back();

	std::cout << liststack.size() << std::endl;

	liststack.push_back(3);
	liststack.push_back(5);
	liststack.push_back(737);
	//[...]
	liststack.push_back(0);

	std::list<int>::iterator listit = liststack.begin();
	std::list<int>::iterator listite = liststack.end();

	++listit;
	--listit;
	while (listit != listite)
	{
		std::cout << *listit << std::endl;
		++listit;
	}

	return 0;
}