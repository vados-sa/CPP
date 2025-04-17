#include "Fixed.hpp"

Fixed::Fixed () 
	: fixed_point(0)// default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& other) // copy constructor
	: fixed_point(other.fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;

}

Fixed& Fixed::operator = (const Fixed &other) // copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // avoid self-assignment
		this->fixed_point = other.fixed_point;
	this->getRawBits();
	return *this;
}

Fixed::~Fixed () // destructor
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const // returns the raw value of the fixed-point value.
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void Fixed::setRawBits( int const raw ) // set the raw value of the fixed-point number.
{
	fixed_point = raw;
}