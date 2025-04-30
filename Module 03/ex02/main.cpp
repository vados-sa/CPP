#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n=== Testing FragTrap Attributes ===" << std::endl;
    std::cout << "FragTrap Name: " << frag.getName() << std::endl;
    std::cout << "Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << frag.getAttackDamage() << std::endl;

    std::cout << "\n=== Testing FragTrap Actions ===" << std::endl;
    frag.attack("Target Dummy");
    frag.takeDamage(20);
    frag.beRepaired(15);

    std::cout << "\n=== Testing FragTrap Special Ability ===" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n=== Destroying FragTrap ===" << std::endl;

    return 0;
}