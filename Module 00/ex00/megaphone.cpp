#include <string>
#include <iostream>

/**
 * @file megaphone.cpp
 * @brief Converts command-line input to uppercase and prints it.
 *
 * - `std::string`: Used for string manipulation instead of C-style strings.
 * - `std::cout` & `std::endl`: Standard output stream, replacing `printf`.
 * - `std::toupper()`: Function from `<cctype>` for character conversion.
 * - `.length()`: C++ string method for getting string size.
 * - Implicit string concatenation with `+=`: More convenient than `strcat`.
 */
int	main(int ac, char **av)
{
	std::string s;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			s += av[i];
		
		for (unsigned long i = 0; i < s.length(); i++)
			s[i] = std::toupper(s[i]);
		
		std::cout << s << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
	return 0;
}
