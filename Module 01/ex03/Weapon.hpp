#include <iostream>

#ifndef WEAPON_H
#define WAEPON_H

class Weapon {

	private:
		std::string type; 

	public:
		Weapon(std::string type);
		const std::string& getType(); // returns a constant reference to type.
		void setType(std::string new_value); // sets type using the new value passed as a parameter
		void setWeapon(Weapon type);

};

#endif