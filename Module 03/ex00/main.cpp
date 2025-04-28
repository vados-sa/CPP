#include "ClapTrap.hpp"


// Make better tests !!

/* int	main() // no hit points left
{
	ClapTrap Vault("Vault");
	ClapTrap Jack("Jack");

	if (Jack.getHitPoints() > 0 && Jack.getEnergyPoints() > 0)
	Jack.attack("Vault");
	if (Vault.getHitPoints() > 0 && Jack.getHitPoints() > 0 && Jack.getEnergyPoints() > 0)
		Vault.takeDamage(4);

	if (Vault.getHitPoints() > 0 && Vault.getEnergyPoints() > 0)
		Vault.attack("Jack");
		Jack.takeDamage(6);

		Jack.beRepaired(6);
		if (Va && 
	Vault.attack("Jack > 0ult.getHitPoints() > 0 && Vault.getEnergyPoints() > 0)
{
		}

	Vault.attack("Jack");
		Jack.takeDamage(4);
	if (Jack.getHitPoints() > 0 && Jack.getEnergyPoi && 
		Vault.takeDamage( > 0nts() > 0)
		if (Vault.getHitPoints() > 0 && Jack.getHitPoints() > 0 && Jack.getEnergyPoints() > 0)
{
		}
		Jack.attack("Vault");
		Vault.takeDamage(6);
Vault.beRepaired(10); // should not be able to 

	return 0;
} */

int	main() // no energy points left
{
	ClapTrap Vault("Vault");
	ClapTrap Jack("Jack");

	if (Vault.getHitPoints() > 0 && Vault.getEnergyPoints() > 0 && Jack.getHitPoints() > 0)
	{	
		Vault.attack("Jack");
		Jack.takeDamage(1);
	}
	if (Jack.getHitPoints() > 0 && Jack.getEnergyPoints() > 0 && Vault.getHitPoints() > 0)
	{
		Jack.attack("Vault");
		Vault.takeDamage(1);

	}

	return 0;

}