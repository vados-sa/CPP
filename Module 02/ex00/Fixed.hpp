#ifndef FIXED_H
#define FIXED_H

class Fixed {
private:
	int fixed_point;
	static const int fractional_bits = 8;

public:
	// default constructor
	// copy constructor
	// copy assignment operator overload
	// destructor
	int getRawBits( void ) const; // returns the raw value of the fixed-point value.
	void setRawBits( int const raw ); // setd the raw value of the fixed-point number.

};

#endif