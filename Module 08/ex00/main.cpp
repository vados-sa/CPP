#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {

	{
		std::cout << "<vector>" << std::endl;
		std::vector<int> v;
    	v.push_back(26); v.push_back(29); v.push_back(50); v.push_back(63);
    	std::vector<int>::iterator v_it = easyfind(v, 26);

    	if (v_it != v.end())
    	    std::cout << "Found: " << *v_it << std::endl;
    	else
    	    std::cout << "Not found" << std::endl;
	}
	{
		std::cout << "<list>" << std::endl;
		std::list<int> l;  l.push_back(2); l.push_back(4); l.push_back(6);
		std::list<int>::iterator l_it = easyfind(l, 4);
		if (l_it != l.end())
    	    std::cout << "Found: " << *l_it << std::endl;
    	else
    	    std::cout << "Not found" << std::endl;
	}
	
	{
		std::cout << "<deque>" << std::endl;
		std::deque<int>  d;  d.push_back(7); d.push_back(8); d.push_back(9);
		std::deque<int>::iterator d_it = easyfind(d, 9);
		if (d_it != d.end())
    	    std::cout << "Found: " << *d_it << std::endl;
    	else
    	    std::cout << "Not found" << std::endl;
	}
	
	return 0;
}