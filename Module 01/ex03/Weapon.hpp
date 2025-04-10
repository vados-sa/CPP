#include <iostream>

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {

	private:
		std::string type; 

	public:
		Weapon(std::string weapon_type);
		const std::string& getType(); // returns a constant reference to type.
		void setType(std::string new_value); // sets type using the new value passed as a parameter

};

#endif