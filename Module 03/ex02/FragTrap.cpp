#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called." << std::endl; 
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name)
{
	std::cout << "Frag Trap Constructor called for " << name << "." << std::endl; 
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap (const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &other)
{
	std::cout << "FragTrap Copy Assignment Operator called for " << other.name << "." << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

FragTrap::~FragTrap()
{
	if (energy_points > 0 && hit_points > 0)
		std::cout << name << " is still alive!" << std::endl;
	std::cout << "Frag Trap Destructor called on " << name << "." << std::endl; 
}

void FragTrap::highFivesGuys()
{
	std::cout << "High Five y'all!!" << std::endl;
}