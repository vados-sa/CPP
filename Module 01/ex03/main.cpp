//#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); // set wapon using reference - it's always there.
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club); // change using pointer - doesn't exits at first.
		jim.attack();
		club.setType("some other type of club"); // it's not being set
		jim.attack();
	}

	return 0;
}