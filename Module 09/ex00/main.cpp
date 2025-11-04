#include "BitcoinExchange.hpp"
#include <iostream>

int main (int ac, char *av[]) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	
	BitcoinExchange btc(av[1]);
	// maybe use a try and catch
	btc.loadDB();
	//btc.printDB();
	//btc.processInputFile();
	
	return 0;
}