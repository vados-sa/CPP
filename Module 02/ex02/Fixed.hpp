#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

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
	
	// Conversions
	int getRawBits( void ) const; // returns the raw value of the fixed-point value.
	void setRawBits( int const raw ); // setd the raw value of the fixed-point number.
	float toFloat( void ) const; // converts the fixed-point value to a floating-point value.
	int toInt( void ) const; //  converts the fixed-point value to an integer value.

	// Comparisions
	// bool -> a question is being asked. const -> the fucntion won't modify anything
	bool operator>(const Fixed& obj) const; 
	bool operator<(const Fixed& obj) const;
	bool operator>=(const Fixed& obj) const;
	bool operator<=(const Fixed& obj) const;
	bool operator==(const Fixed& obj) const;
	bool operator!=(const Fixed& obj) const;

	// Arithmetic
	// return a value and not modify either operand
	Fixed operator+(const Fixed& obj) const;
	Fixed operator-(const Fixed& obj) const;
	Fixed operator*(const Fixed& obj) const;
	Fixed operator/(const Fixed& obj) const;

	// Increment / Decrement
	Fixed& operator++();    // prefix return by reference
	Fixed operator++(int);  // postfix returns a copy. `int` is a dummy argument
	Fixed& operator--();
	Fixed operator--(int);

	// Min / Max
	static Fixed& min(Fixed& a, Fixed& b); //  returns a reference to the smallest one.
	static const Fixed& min(const Fixed& a, const Fixed& b); //  returns a reference to the smallest one.
	static Fixed& max(Fixed& a, Fixed& b); // returns a reference to the greatest one.
	static const Fixed& max(const Fixed& a, const Fixed& b); // returns a reference to the greatest one.
};

// Output stream overload
std::ostream& operator<<(std::ostream& out, const Fixed& obj); // operator overload function

#endif