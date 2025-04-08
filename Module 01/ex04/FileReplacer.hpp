#ifndef FILEREPLACER_H
#define FILEREPLACER_H

#include <iostream>
#include <fstream>
#include <vector>

class FileReplacer{
private:
	std::string filename;
	std::string s1;
	std::string s2;

	void replace_all(std::string& line);

public:
	FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
	bool process_file();
};

#endif