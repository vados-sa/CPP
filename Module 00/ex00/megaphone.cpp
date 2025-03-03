#include <string>
#include <iostream>

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