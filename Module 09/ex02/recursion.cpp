#include <iostream>
#include <vector>

// Number of digits in N
int nb_of_digits(int N) {
	if (N < 10)
		return 1;
	else
		return 1 + nb_of_digits(N/10);
}

// Print a vector in reverse
void print_vector_reverse(std::vector<char> v, size_t idx) {	
	if (idx == 0) {
		std::cout << std::endl;
		return ;
	}

	std::cout << v[idx - 1] << " ";
	print_vector_reverse(v, idx - 1);
}

// is a palindrome
bool is_palindrome(const std::string& s) {
	if (s.size() <= 1)
		return true;

	std::string lower = s;
	for (size_t i = 0; i < lower.size(); i++)
		lower[i] = tolower(lower[i]);

	if (lower.front() != lower.back())
		return false;

	std::string smaller = lower.substr(1, lower.size() - 2);
	return is_palindrome(smaller);
}

// Factorial of a number
int factorial(int n) {
	if (n == 0 )
		return 1;
	return n * factorial(n - 1);
}

// Sum of digits of an integer
int sum_of_digits(int n) {
	if (n < 0)
		n -= n;
	if (n < 10)
		return n;
	return (n % 10) + sum_of_digits(n / 10);
}

int main () {

	{
		int N = 1234567890;
		std::cout << "Number of Digits in " << N << ": " << nb_of_digits(N) << std::endl;
	}

	std::cout << std::endl;

	{	
		std::vector<char> v;
		for (int i = 97; i < 97 + 26; i++)
			v.push_back(static_cast<char>(i));
		std::cout << "Vector before: ";
		for (int i = 0; i < 26; i++)
			std::cout << v.at(i) << " ";
		std::cout << std::endl;
		std::cout << "Vector after: ";
		print_vector_reverse(v, v.size());
	}

	std::cout << std::endl;

	{
		std::string s = "Madam";
		std::cout << "Is " << s << " a Palindrome: ";
		is_palindrome(s) ? std::cout << "true" : std::cout << "false";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		int fact = 5;
		std::cout << "Factorial of " << fact << " is " << factorial(fact) << std::endl;
	}

	std::cout << std::endl;

	{
		int digit = 1234567890;
		std::cout << "Sum of digits of an integer " << digit << " is " << sum_of_digits(digit) << std::endl;
	}

	return 0;
}