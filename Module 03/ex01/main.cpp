#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Scavvy");

    scav.attack("Target");
    scav.guardGate();

    return 0;
}