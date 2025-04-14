#include "Zombie.hpp"

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return ""; // String is all whitespace
    }

    return str.substr(start, end - start + 1);
}


unsigned int get_zombies_amount()
{
	unsigned int n = 0; 
	std::string amount;

	std::cout << "Enter the amount of zombies: ";
	while(true)
	{
		std::getline(std::cin, amount);
		bool is_valid = !amount.empty();
		for (size_t i = 0; i < amount.length(); i++)
        {
            if (!std::isdigit(amount[i]))
            {
                is_valid = false;
                break ;
            }
        }
		if (!is_valid)
		{
			std::cout << "Invalid number of zombies. Try again: ";
			continue ;
		}
		n = 0;
        for (size_t i = 0; i < amount.length(); i++)
        {
            n = n * 10 + (amount[i] - '0'); // convert each character to its numeric value
        }

        if (n <= 0)
        {
            std::cout << "The number must be greater than 0. Try again: ";
            continue ;
        }
		break ;
	}
	return n;
}