#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

void schoolTest() {
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

void testBigSequential() {
	std::cout << "---- Test more than 10000 numbers ----" << std::endl;

	Span sp = Span(10002);
	
	for (unsigned int i = 0; i < sp.getN(); i++)
		sp.addNumber(i);
		
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	std::cout << "Try to add a 10003rd number: ";
	sp.addNumber(10003);
}

void testAddRange() {
	std::cout << "---- Test adding range ----" << std::endl;

	std::vector<int> range(10000);

	std::srand(time(NULL));
	std::generate(range.begin(), range.end(), std::rand);
	
	Span sp = Span(10000);
	sp.addRange(range.begin(), range.end());

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

int main()
{
	try
	{
		schoolTest();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		testBigSequential();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		testAddRange();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}