#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");

    std::cout << "\n=== Testing ClapTrap Attributes ===" << std::endl;
    std::cout << "ClapTrap Name: " << "Clappy" << std::endl;
    std::cout << "Hit Points: " << clap1.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap1.getEnergyPoints() << std::endl;

    std::cout << "\n=== Testing ClapTrap Actions ===" << std::endl;
    clap1.attack("Target Dummy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    std::cout << "\n=== Testing ClapTrap Energy Depletion ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        clap1.attack("Target Dummy");
    }
    clap1.attack("Target Dummy"); // Should fail due to 0 energy points

    std::cout << "\n=== Testing ClapTrap Death ===" << std::endl;
    clap1.takeDamage(20); // Should reduce hit points to 0
    clap1.attack("Target Dummy"); // Should fail due to 0 hit points
    clap1.beRepaired(5); // Should fail due to 0 hit points

    std::cout << "\n=== Destroying ClapTraps ===" << std::endl;

    return 0;
}