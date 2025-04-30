#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("Diamond");

    std::cout << "\n=== Testing DiamondTrap Attributes ===" << std::endl;
    std::cout << "Hit Points: " << diamond.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << diamond.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << diamond.getAttackDamage() << std::endl;

    std::cout << "\n=== Testing DiamondTrap Actions ===" << std::endl;
    diamond.attack("Target Dummy");
    diamond.takeDamage(20);
    diamond.beRepaired(15);

    std::cout << "\n=== Testing DiamondTrap Special Ability ===" << std::endl;
    diamond.whoAmI();

    std::cout << "\n=== Destroying DiamondTrap ===" << std::endl;

    return 0;
}
