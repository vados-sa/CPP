#include "Zombie.hpp"

int	main()
{
	int N;
	std::cout << "Enter the amount of zombies: ";
	std::cin >> N;
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies." << std::endl;
		return 1;
	}
	
	std::string name;
	std::cout << "Enter the name of the zombies: ";
	std::cin >> name;
	std::cout << std::endl;

	Zombie *zombie = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		zombie[i].announce();

	std::cout << std::endl;
	delete[] zombie;
	return 0;
}
