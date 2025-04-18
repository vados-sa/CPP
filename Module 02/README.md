** Ad-hoc polymorphism, operator overloading
and the Orthodox Canonical class form ** 

# The Orthodox Canonical class form
### Default Constructor
`Class();`
Member function that it's called to initialize an object with default values when an object is instatiated.
### Parameterized Constructor
`Class(data_type parameter1, data_type parameter2, ...)`
(Not required in the subjects so far)
Initializes an object with specific values provided as arguments during the object's instantiation.
### Copy Constructor
`Class(const Class &other);`
Initializes a new object as a copy of an existing object.
Can be useful when passing an object by value or when we need to duplicate an object.
### Copy Assignment Operator
`Class &operator=(const Class &other)`
Assigns the value of one object to another already-existing object.
### Destructor
`~Class();`
Get's called when an object goes out of scope or is specifically deleted.
It is used to clean up resources.

# Operator Overloading
Operators are predefined to operate on variables of built-in data type only. For example: ` int a; float b, sum; sum = a + b; `.
Trying to add two objects that are of user-defined type using "+" operator would not be allowed.

Now, if the user wants to make the operator “+” add two class objects, the user has to redefine the meaning of the “+” operator such that it adds two class objects. This is done by using the concept of “Operator overloading”. So the main idea behind “Operator overloading” is to use C++ operators with class variables or class objects. Redefining the meaning of operators really does not change their original meaning; instead, they have been given additional meaning along with their existing ones.

` Interger& operator=( Interger const & rhs ); `
` Interger operator+( Interger const & rhs ) const; `
### An operator overloading fucntion teaches C++ what the operator should do for a specific class.

# Fixed-Point
Fixed-point is a number type that stores real (decimal) numbers using integers, by dedicating a fixed number of bits to represent the **fractional part**. It offers a balance between the wide range of integers and the precision of floating-point numbers.

Fixed-point is especially useful in:
- Embedded systems (where floating-point hardware is unavailable)
- Audio/DSP applications
- Games and graphics (e.g., shaders, pixel precision)
- Performance-critical systems

In C++, we simulate fixed-point behavior by storing a scaled integer and converting to/from `int` and `float` using bitwise operations and scaling factors.

### From `int` to Fixed-Point

Shift the integer to the left by `n` bits, where `n` is the number of fractional bits:

` fixed_point = int_value << fractional_bits; `
 
This is equivalent to:
` fixed_point = int_value * (1 << fractional_bits); `

### From float to Fixed-Point
Multiply the float by 2^n and round to the nearest integer:

`fixed_point = roundf(float_value * (1 << fractional_bits));` 1 << n is a fast way to compute 2^n using a bit shift.

### From Fixed-Point to int
Shift the stored value to the right by n bits to remove the fractional part:

`int_value = fixed_point >> fractional_bits;` This discards the decimal precision.

### From Fixed-Point to float
Convert the fixed-point integer to a float, then divide by 2^n:
`float_value = static_cast<float>(fixed_point) / (1 << fractional_bits);` This restores the real number with decimal precision.


