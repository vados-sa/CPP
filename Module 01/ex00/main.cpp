#include "Zombie.hpp"

int	main()
{
	std::string name;
	bool		iterate = true;
	
	while(iterate) // randomChump
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
		iterate = false;
	}
	iterate = true;
	while(iterate) // newZombie
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
		iterate = false;
	}

	return 0;
}