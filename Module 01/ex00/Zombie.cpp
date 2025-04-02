#include "Zombie.hpp"

Zombie::Zombie(std::string new_name)
{
	name = new_name;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed." << std::endl << std::endl;
}

void Zombie::announce(void)
{
	std::cout << std::endl << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
