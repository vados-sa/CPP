// forbidden fucntions: std::string::replace
/*  Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely */

#include <iostream>
#include <fstream>

int	main(int ac, char *av[]) // filename, s1 and s2
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments. Usage: ./sed_is_for_losers <filename> s1 s2" << std::endl;
		return 1;
	}
	if (!av[2] || !av[3])
		return 0; // maybe just create the replacemen file with a copy of the file
	std::ifstream input_stream(av[1]);
	if (!input_stream)
	{
		std::cerr << "Can't open input file!";
		return 1;
	}
	// open the file <filename> and copy its content into a new file <filename>.replace
	// replace every occurence of s1 with s2
	return 0;
}