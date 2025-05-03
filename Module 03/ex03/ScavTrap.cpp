#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called." << std::endl; 
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name)
{
	std::cout << "Scav Trap Constructor called for " << name << "." << std::endl; 
	//hit_points = 100;
	energy_points = 50;
	//attack_damage = 20;
}

ScavTrap::ScavTrap (const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &other)
{
	std::cout << "ScavTrap Copy Assignment Operator called for " << other.name << "." << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Trap Destructor called on " << name << "." << std::endl; 
}

void ScavTrap::attack(const std::string& target)
{
	if (energy_points == 0 || hit_points == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " ferociously attacks " << target
			  << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}