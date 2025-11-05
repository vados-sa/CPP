#pragma once
#include <map>
#include <string>

class BitcoinExchange {
		std::map<std::string, double> db_info;
		std::string file;

	public:
		BitcoinExchange(const std::string& input_file);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDB();
		//void printDB() const;
		void processInputFile();
		double findExchangeRate(const std::string& date) const;
};