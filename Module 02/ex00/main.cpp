#include "Fixed.hpp"

int main( void )
{
	Fixed a; // default constructor called
	Fixed b( a ); // copy constructor called
	Fixed c; // default constructor called

	c = b; // copy assigment operator called - assigns b to c

	std::cout << a.getRawBits() << std::endl; // getRawBits method is called on object a
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}