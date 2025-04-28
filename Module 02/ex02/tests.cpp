#include "Fixed.hpp"

void test_comparison_operators()
{
    Fixed a(10);
    Fixed b(5);
    Fixed c(10);

    std::cout << "Testing Comparison Operators:" << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;

    std::cout << std::endl;
}

void test_arithmetic_operators()
{
    Fixed a(10);
    Fixed b(5);

    std::cout << "Testing Arithmetic Operators:" << std::endl;

    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;

    std::cout << std::endl;
}

void test_increment_decrement_operators()
{
    Fixed a;

    std::cout << "Testing Increment/Decrement Operators:" << std::endl;

    std::cout << "Initial value: " << a << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << std::endl;
}

void test_min_max_functions()
{
    Fixed a(10);
    Fixed b(5);

    std::cout << "Testing Min/Max Functions:" << std::endl;

    std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;

    const Fixed c(20);
    const Fixed d(15);

    std::cout << "Min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "Max(c, d): " << Fixed::max(c, d) << std::endl;

    std::cout << std::endl;
}