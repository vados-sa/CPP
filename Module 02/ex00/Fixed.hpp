#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
	int fixed_point;
	static const int fractional_bits = 8;

public:
	Fixed(); // default constructor
	Fixed(const Fixed &other); // copy constructor
	Fixed &whatevergoeshere(const Fixed &other); // copy assignment operator overload
	~Fixed(); // destructor
	int getRawBits( void ) const; // returns the raw value of the fixed-point value.
	void setRawBits( int const raw ); // setd the raw value of the fixed-point number.
};

#endif