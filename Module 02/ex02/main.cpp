#include "Fixed.hpp"

void test_comparison_operators();
void test_arithmetic_operators();
void test_increment_decrement_operators();
void test_min_max_functions();

int main()
{
    std::cout << "=== Fixed Class Tests ===" << std::endl;

    test_comparison_operators();
    test_arithmetic_operators();
    test_increment_decrement_operators();
    test_min_max_functions();

    return 0;
}

/* 
// main() from the subject
int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */