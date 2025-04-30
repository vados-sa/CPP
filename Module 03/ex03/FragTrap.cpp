#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Frag Trap Default constructor called." << std::endl; 
}

FragTrap::FragTrap(std::string name) // I'm not yet sure that's the right way.
	:ClapTrap(name)
{
	std::cout << "Frag Trap Constructor called for " << name << "." << std::endl; 
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag Trap Destructor called on " << name << "." << std::endl; 
}

void FragTrap::highFivesGuys()
{
	std::cout << "High Five y'all!!" << std::endl;
}