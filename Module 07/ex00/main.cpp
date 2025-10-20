#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;

	::swap<int>( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;
	
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout << std::endl;
	// tie case
    int e = 42, f = 42;
    std::cout << "tie min picks second? " << ( &::min(e, f) == &f ? "yes" : "no" ) << std::endl;
    std::cout << "tie max picks second? " << ( &::max(e, f) == &f ? "yes" : "no" ) << std::endl;

	std::cout << std::endl;
	std::string s1 = "same", s2 = "same";
    std::cout << "tie min(str) picks second? " << ( &::min(s1, s2) == &s2 ? "yes" : "no" ) << std::endl;
    std::cout << "tie max(str) picks second? " << ( &::max(s1, s2) == &s2 ? "yes" : "no" ) << std::endl;

	return 0;
}