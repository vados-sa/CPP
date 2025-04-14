#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *strPTR = &s; // A pointer to s
	std::string &strREF = s; // Reference to s

	std::cout << &s << std::endl; // The memory address of the s
	std::cout << strPTR << std::endl; // The memory address held by stringPTR
	std::cout << &strREF << std::endl; // The memory address held by stringREF

	std::cout << s << std::endl; // Value of s
	std::cout << *strPTR << std::endl; // Value of what stringPTR points to
	std::cout << strREF << std::endl; // Value that strREF refers to

	return 0;
}
