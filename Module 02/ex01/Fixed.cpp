#include "Fixed.hpp"

Fixed::Fixed () // default constructor
	: fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int n)
{
	fixed_point = n << fractional_bits; // shift left to make room for fractional bits
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float n)
{
	fixed_point = roundf(n * (1 << fractional_bits)); // scale and round - bitwise shift only works on int
	std::cout << "Float constructor called" << std::endl;
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
	return *this;
}

Fixed::~Fixed () // destructor
{
	std::cout << "Destructor called" << std::endl;
}

/* fixed → float */
float Fixed::toFloat( void ) const
{
	return static_cast<float>(fixed_point) / (1 << fractional_bits);
}

/* fixed → int */
int Fixed::toInt( void ) const
{
	return fixed_point >> fractional_bits; // drops the fractional part by shifting right 8 bits.
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

/* 
* Overload the `<<` operator for class Fixed, to print floats.
*
* std::ostream&             // return type: a reference to std::cout
* operator<<                // the operator we are overloading (<<)
* (std::ostream& out,       // first parameter: the output stream (usually std::cout)
* const Fixed& obj)         // second parameter: the thing being printed (the object)
*/
std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat(); // insert the float value into the output stream
	return out; // return the stream
}
