#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creating ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");

    std::cout << "\n=== Testing ScavTrap Attributes ===" << std::endl;
    std::cout << "ScavTrap Name: " << scav.getName() << std::endl;
    std::cout << "Hit Points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scav.getAttackDamage() << std::endl;

    std::cout << "\n=== Testing ScavTrap Actions ===" << std::endl;
    scav.attack("Target Dummy");
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "\n=== Testing ScavTrap Special Ability ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Destroying ScavTrap ===" << std::endl;

    return 0;
}