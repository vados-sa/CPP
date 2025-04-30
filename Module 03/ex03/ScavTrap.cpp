#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) // I'm not yet sure that's the right way.
	:ClapTrap(name)
{
	std::cout << "Scav Trap Constructor called for " << name << "." << std::endl; 
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	if (energy_points > 0 && hit_points > 0)
		std::cout << name << " is still alive!" << std::endl;
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