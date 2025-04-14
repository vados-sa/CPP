#include "Zombie.hpp"

int	main()
{
	std::string name;
	
	// randomChump
	std::cout << "Enter a name for your random chump: ";
	std::cin >> name;
	randomChump(name);
	
	// newZombie
	std::cout << "Enter a name for your new Zombie: ";
	std::cin >> name;
	Zombie *zombie = newZombie(name);
	zombie->announce();
	delete zombie;

	return 0;
}