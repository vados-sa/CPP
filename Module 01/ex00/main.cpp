#include "Zombie.hpp"

int	main()
{
	std::string name;
	
	while(true) // randomChump
	{
		std::cout << "Enter a name for your random Chump: ";
		std::getline(std::cin, name);
		name = trim(name);
		if(name.empty())
		{
			std::cout << "Empty names are not valid. Please try again." << std::endl;
			continue ;
		}
		randomChump(name);
		break ;
	}
	while(true) // newZombie
	{
		std::cout << "Enter a name for your new Zombie: ";
		std::getline(std::cin, name);
		if(name.empty())
		{
			std::cout << "Empty names are not valid. Please try again." << std::endl;
			continue ;
		}
		Zombie *zombie = newZombie(name);
		zombie->announce();
		delete zombie;
		break ;
	}

	return 0;
}