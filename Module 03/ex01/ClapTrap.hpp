#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap {

protected:
	std::string name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string name); // constructor
	ClapTrap(const ClapTrap& other); // copy constructor
	ClapTrap& operator = (const ClapTrap& other); // copy assignment operator overload
	~ClapTrap(); // destructor

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int getHitPoints() const;
	int getEnergyPoints() const;
	std::string getName() const;
	int getAttackDamage() const;
};

#endif