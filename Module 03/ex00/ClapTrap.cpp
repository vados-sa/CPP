#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called." << std::endl; 
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called for " << name << "." << std::endl; 
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap (const ClapTrap& other)
	: name(other.name)
{
	std::cout << "Copy constructor called" << std::endl;

}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->name = other.name;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called on " << name << "." << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
	if(energy_points == 0 || hit_points == 0)
	{
		if (energy_points == 0)
			std::cout << "ClapTrap " << name << " has 0 energy points left, it cannot attack another ClapTrap!" << std::endl;
		if (hit_points == 0)
			std::cout << "ClapTrap " << name << " is dead! It has lost all his hit points" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing it to lose points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points == 0)
	{
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return ;
    }
	std::cout << "ClapTrap " << name << " is attacked, losing " << amount << " hit points!" << std::endl;
	
	hit_points -= amount;
	if (hit_points < 0) hit_points = 0;
	attack_damage += amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(energy_points == 0 || hit_points == 0)
	{
		if (energy_points == 0)
			std::cout << "ClapTrap " << name << " has 0 energy points left, it cannot repair itself anymore!" << std::endl;
		if (hit_points == 0)
			std::cout << "ClapTrap " << name << " is dead! It has lost all his hit points" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << name << " repairs itself regaining " << amount << " hit points!" << std::endl; // not very clear what <damage> should be
	
	hit_points = hit_points + amount;

	energy_points--;
}

int ClapTrap::getHitPoints() const
{
	return hit_points;
}

int ClapTrap::getEnergyPoints() const
{
	return energy_points;
}