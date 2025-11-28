#include "BitcoinExchange.hpp"
#include <iostream>

int main (int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	try {
		BitcoinExchange btc(av[1]);
		btc.loadDB();
		//btc.printDB();
		btc.processInputFile();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}