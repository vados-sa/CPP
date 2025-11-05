#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

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
		std::string header; 
		std::getline(db_file, header);

		while (std::getline(db_file, line)) {
			if (line.empty()) continue ;
			if (!line.empty() && line[line.size() - 1] == '\r')
				line.erase(line.size() - 1);

			std::size_t pos = line.find(',');
			if (pos == std::string::npos) {
				std::cout << "Invalid line: " << line << std::endl;
				continue ;
			}

			std::string date = line.substr(0, pos);
			std::string valueStr = line.substr(pos + 1);
	
			std::istringstream vs(valueStr);
			double value = 0.0;
			vs >> value;
			if (!vs) {
				std::cout << "Invalid number: " << valueStr << std::endl;
				continue ;
			}
			db_info[date] = value;
		}
	}
	else throw std::runtime_error("data.csv could not open");
}

static std::string validadeDate(std::string line, std::size_t pos) {
	bool badInput = false;
	std::string date = line.substr(0, pos);

	std::istringstream in(date);
	int y, m, d;
	char c1, c2;
	if (!(in >> y >> c1 >> m >> c2 >> d) || c1 != '-' || c2 != '-' || in.peek() != EOF) 
		badInput = true;
	
	//std::cout << y << " " << m << " " << d << std::endl;

	time_t now = std::time(NULL);
	std::tm* lt = std::localtime(&now);
	int currentYear = lt->tm_year + 1900;

	if (y < 1900 || y > currentYear)
		badInput = true;
	
	if (m < 1 || m > 12)
		badInput = true;
	
	bool leap = false;
	if ((y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0)))
		leap = true;

	if (m == 2) {
		if (d < 1 || d > (leap ? 29 : 28)) badInput = true;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || d > 30) badInput = true;
	}
	else if (d < 1 || d > 31)
		badInput = true;
	
	if (badInput == true) {
		std::cout << "Error: bad input => " << date << std::endl;
		date = "";
	}

	return date;
}

static double validadeExchangeRate(std::string line, std::size_t pos) {
	std::string valueStr = line.substr(pos + 3);
	std::istringstream vs(valueStr);
	double value = 0.0;
	vs >> value;
	if (!vs) {
		std::cout << "Error: bad input => " << line << std::endl;
		return -1;
	}
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return -1;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return -1;
	}

	return value;
}

void BitcoinExchange::processInputFile() {
	std::ifstream input_file(file);
	std::string line;
	if (input_file.is_open()) {
		std::string header; 
		std::getline(input_file, header);

		while (std::getline(input_file, line)) {
			if (line.empty()) continue ;

			std::size_t pos = line.find(" | ");
			if (pos == std::string::npos) {
				std::cout << "Error: bad input => " << line << std::endl;
				continue ;
			}

			std::string date = validadeDate(line, pos);
			if (date.empty())
				continue ;

			double value = validadeExchangeRate(line, pos);
			if (value == -1)
				continue ;

			// lookup exchange rate
			// compute and print
		}
	}
	else throw std::runtime_error("input file could not open");
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