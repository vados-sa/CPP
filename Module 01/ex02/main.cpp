#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *strPTR = &s; // a pointer to the string.
	std::string &strREF = s; // reference to the string

	std::cout << &s << std::endl; // The memory address of the string variable
	std::cout << strPTR << std::endl; // The memory address held by stringPTR
	std::cout << &strREF << std::endl; // The memory address held by stringREF

	std::cout << s << std::endl;
	std::cout << *strPTR << std::endl;
	std::cout << strREF << std::endl;

	return 0;
}
