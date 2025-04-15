#include "Fixed.hpp"

Fixed::Fixed () // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &copy) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	(void)copy;
}

Fixed &whatevergoeshere(const Fixed &copy) // copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	(void)copy;
}

Fixed::~Fixed () // destructor
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const // returns the raw value of the fixed-point value.
{
	return fixed_point;
}
void Fixed::setRawBits( int const raw ) // setd the raw value of the fixed-point number.
{
	fixed_point = raw / fractional_bits;
}