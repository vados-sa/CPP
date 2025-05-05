#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator = (const Animal& other);
		virtual ~Animal();

		virtual void makeSound() const; // print animal's aproriate sound
		std::string getType() const;
};
