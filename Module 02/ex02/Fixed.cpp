#include "Fixed.hpp"

Fixed::Fixed () : fixed_point(0)
{}

Fixed::Fixed (const int n)
{
	fixed_point = n << fractional_bits; // shift left to make room for fractional bits
}
Fixed::Fixed(const float n)
{
	fixed_point = roundf(n * (1 << fractional_bits)); // scale and round - bitwise shift only works on int
}

Fixed::Fixed (const Fixed& other) : fixed_point(other.fixed_point)
{}

Fixed& Fixed::operator = (const Fixed &other) // copy assignment operator overload
{
	if (this != &other) // avoid self-assignment
		this->fixed_point = other.fixed_point;
	return *this;
}

Fixed::~Fixed () // destructor
{}

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

// Comparisions
// bool -> a question is being asked. const -> the fucntion won't modify anything

bool Fixed::operator>(const Fixed& obj) const
{
	return this->fixed_point > obj.fixed_point;
} 

bool Fixed::operator<(const Fixed& obj) const
{
	return this->fixed_point < obj.fixed_point;
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return this->fixed_point >= obj.fixed_point;
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return this->fixed_point <= obj.fixed_point;
}

bool Fixed::operator==(const Fixed& obj) const
{
	return this->fixed_point == obj.fixed_point;
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return this->fixed_point != obj.fixed_point;
}


// Arithmetic
// return a value and not modify either operand

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed result;

	result.setRawBits(this->fixed_point + obj.fixed_point);
	return result;
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed result;

	result.setRawBits(this->fixed_point - obj.fixed_point);
	return result;
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed result;

	result.setRawBits((this->fixed_point * obj.fixed_point) >> fractional_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	Fixed result;

	result.setRawBits((this->fixed_point << fractional_bits) / obj.fixed_point);
	return result;
}


// Increment / Decrement

Fixed& Fixed::operator++()
{
	this->fixed_point += 1;

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;;

	++(*this);
	return tmp;
}  // postfix returns a copy. `int` is a dummy argument

Fixed& Fixed::operator--()
{
	this->fixed_point -= 1;

	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;;

	--(*this);
	return tmp;
}

// Min / Max

//  returns a reference to the smallest one.
static Fixed& min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
} 

//  returns a reference to the smallest one.
static const Fixed& min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
} 

// returns a reference to the greatest one.
static Fixed& max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
} 

// returns a reference to the greatest one.
static const Fixed& max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
} 
