#include "Fixed.hpp"

int main( void ) {
	Fixed a;	// default constructor called
	Fixed const b( 10 ); // int constructor called
	Fixed const c( 42.42f ); // float constructor called
	Fixed const d( b ); // copy constructor called

	a = Fixed( 1234.4321f );
	// creates temporary object usign float constructor
	// uses copy assignment operator to copy the value into a
	// temp object goes out of scope - it's destroyed
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}