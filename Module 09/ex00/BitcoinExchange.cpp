#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string& input_file) : file(input_file) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: db_info(other.db_info), file(other.file) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {	
		this->db_info = other.db_info;
		this->file = other.file;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDB() {
	std::ifstream db_file("data.csv");
	std::string line;

	if (db_file.is_open()) {
		// discard header line
		std::string header; 
		std::getline(db_file, header);

		while (std::getline(db_file, line)) {
			if (line.empty()) continue;
			if (!line.empty() && line[line.size() - 1] == '\r')
				line.erase(line.size() - 1);

			std::size_t pos = line.find(',');
			if (pos == std::string::npos) {
				std::cout << "Invalid line: " << line << std::endl;
				continue;
			}

			std::string date = line.substr(0, pos);
			std::string valueStr = line.substr(pos + 1);
	
			std::istringstream vs(valueStr);
			double value = 0.0;
			vs >> value;
			if (!vs) {
				std::cout << "Invalid number: " << valueStr << std::endl;
				continue;
			}

			db_info[date] = value;
		}
	}
	else {
		std::cout << "Error: could not open file." << std::endl;
	}
}

/* void BitcoinExchange::printDB() const {
	if (db_info.empty()) {
		std::cout << "[db_info] empty" << std::endl;
		return;
	}
	for (std::map<std::string, double>::const_iterator it = db_info.begin(); it != db_info.end(); ++it) {
		std::cout << it->first << " => " << std::setprecision(10) << it->second << std::endl;
	}
} */