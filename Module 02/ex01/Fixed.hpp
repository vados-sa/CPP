#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath> // roundf

class Fixed {
private:
	int fixed_point;
	static const int fractional_bits = 8; // before it was static const int -> not sure if it should stay like that

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& other); // copy constructor
	Fixed& operator = (const Fixed& other); // copy assignment operator overload
	~Fixed(); // destructor
	
	int getRawBits( void ) const; // returns the raw value of the fixed-point value.
	void setRawBits( int const raw ); // setd the raw value of the fixed-point number.
	float toFloat( void ) const; // converts the fixed-point value to a floating-point value.
	int toInt( void ) const; //  converts the fixed-point value to an integer value.
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj); // operator overload function

#endif