#include "Zombie.hpp"

int	main()
{
	unsigned int n = get_zombies_amount();
	
	std::string name;
	std::cout << "Enter the name of the zombies: ";
	while(true)
	{
		std::getline(std::cin, name);
		name = trim(name);
		if(name.empty())
		{
			std::cout << "Empty names are not valid. Please try again." << std::endl;
			continue ;
		}
		break ;
	}
	
	std::cout << std::endl;

	Zombie *zombie = zombieHorde(n, name);

	for (unsigned int i = 0; i < n; i++)
		zombie[i].announce();

	std::cout << std::endl;
	delete[] zombie;
	return 0;
}
