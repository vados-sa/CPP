#include "Span.hpp"
#include <iostream>

void school_test() {
	std::cout << "---- 42 test ----" << std::endl;

	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void test_big_sequential() {
	std::cout << "---- Test more than 10000 numbers ----" << std::endl;

	Span sp = Span(10002);
	
	for (unsigned int i = 0; i < sp.getN(); i++)
		sp.addNumber(i);
		
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	std::cout << "Try to add a 10003rd number: ";
	sp.addNumber(10003);
}

void test_big_addRange() {
	std::cout << "---- Test adding range ----" << std::endl;

	std::vector<int> range;

	for (int i = 0; i < 1000; i++)
		range.push_back(i);
	
	Span sp = Span(1000);
	sp.addRange(range.begin(), range.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
	try
	{
		school_test();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		test_big_sequential();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		test_big_addRange();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}