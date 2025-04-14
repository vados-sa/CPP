#include "Zombie.hpp"

int	main()
{
	std::string name;
	
	while(true) // randomChump
	{
		std::cout << "Enter a name for your random chump: ";
		std::getline(std::cin, name);
		name = trim(name);
		if(name.empty())
		{
			std::cout << "Please enter a valid name for your random chump." << std::endl;
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
			std::cout << "Please enter a valid name for your random chump." << std::endl;
			continue ;
		}
		Zombie *zombie = newZombie(name);
		zombie->announce();
		delete zombie;
		break ;
	}

	return 0;
}