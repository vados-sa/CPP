#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << name << " destroyed." << std::endl;
}

void Zombie::setName(std::string new_name)
{
	name = new_name;
}

void Zombie::announce(void)
{
	std::cout << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
