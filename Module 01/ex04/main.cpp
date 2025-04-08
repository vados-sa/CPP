#include <iostream>
#include <fstream>
#include <vector>

// replace s1 with s2.
void replace_all(std::string& s, const std::string& s1, const std::string& s2)
{
    size_t pos = 0;
	if (s1.empty())
		return ;
    while ((pos = s.find(s1, pos)) != std::string::npos)
	{
        s.erase(pos, s1.length());
        s.insert(pos, s2);
        pos += s2.length();
    }
}

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments. Usage: ./sed_is_for_losers <filename> s1 s2" << std::endl;
		return 1;
	}
	
	std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

	// open file
	std::ifstream input_stream(av[1]);
	if (!input_stream)
	{
		std::cerr << "Error: Could not open input file: " << filename << std::endl;
		return 1;
	}
	
	// create new file
	std::string output_filename = filename + ".replace";
	std::ofstream output_stream (output_filename);
	if (!output_stream) {
		std::cerr << "Error: Could not create output file: " << output_filename << std::endl;
		return 1;
	}

	// process the file line by line
	std::string line;
	while(getline(input_stream, line))
	{
		replace_all(line, av[2], av[3]);
		output_stream << line << std::endl;
	}

	return 0;
}