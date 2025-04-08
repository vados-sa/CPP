#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

void FileReplacer::replace_all(std::string& line)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

bool FileReplacer::process_file()
{
		if(s1.empty())
		{
			std::cerr << "Error: s1 cannot be empty." << std::endl;
			return false;
		}
		
		// open file
		std::ifstream input_stream(filename);
		if (!input_stream)
		{
			std::cerr << "Error: Could not open " << filename << std::endl;
			return false;
		}
		
		// create output file
		std::string output_filename = filename + ".replace";
		std::ofstream output_stream (output_filename);
		if (!output_stream) {
			std::cerr << "Error: Could not create " << output_filename << std::endl;
			return false;
		}
	
		// process the file line by line
		std::string line;
		while(std::getline(input_stream, line))
		{
			replace_all(line);
			output_stream << line << std::endl;
		}
	
		return true;
}