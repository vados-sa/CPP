#include "Zombie.hpp"

int	main()
{
	std::string name;
	
	// randomChump
	std::cout << "Enter a name for your random Chump: ";
	while(true)
	{
		std::getline(std::cin, name);
		name = trim(name);
		if(name.empty())
		{
			std::cout << "Empty names are not valid. Please try again: ";
			continue ;
		}
		randomChump(name);
		break ;
	}
	
	// newZombie
	std::cout << "Enter a name for your new Zombie: ";
	while(true)
	{
		std::getline(std::cin, name);
		if(name.empty())
		{
			std::cout << "Empty names are not valid. Please try again: ";
			continue ;
		}
		Zombie *zombie = newZombie(name);
		zombie->announce();
		delete zombie;
		break ;
	}

	return 0;
}