#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::cout << "---- MutantStack ----" << std::endl;
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
	}

	std::cout << std::endl;

	{
		std::cout << "---- std::list ----" << std::endl;
		std::list<int> liststack;

		liststack.push_back(5);
		liststack.push_back(17);

		std::cout << liststack.back() << std::endl;

		liststack.pop_back();

		std::cout << liststack.size() << std::endl;

		liststack.push_back(3);
		liststack.push_back(5);
		liststack.push_back(737);
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
	}

	std::cout << std::endl;

    {
		std::cout << "---- Test: iterate, then mutate ----" << std::endl;

		MutantStack<int> ms;
		for (int i = 1; i <= 5; ++i)
		    ms.push(i);

		std::cout << "Before modifications: ";
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		    std::cout << *it << " ";
		std::cout << std::endl;

		ms.push(42);
		ms.pop();

		std::cout << "After modifications: ";
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		    std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "---- Test: reverse iteration ----" << std::endl;
		MutantStack<int> ms;
		for (int i = 1; i <= 5; ++i)
		    ms.push(i);
			
		std::cout << "Reverse order: ";
		for (MutantStack<int>::reverse_iterator rit = ms.rbegin();
		     rit != ms.rend();
		     ++rit)
		{
		    std::cout << *rit << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "---- Vector-backed MutantStack: ----" << std::endl;
		MutantStack<int, std::vector<int> > vs;
		vs.push(10);
		vs.push(20);
		vs.push(30);
			
		for (MutantStack<int, std::vector<int> >::iterator it = vs.begin(); it != vs.end(); ++it)
		    std::cout << *it << " ";
		std::cout << std::endl;
	}

	return 0;
}