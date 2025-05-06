#pragma once

#include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator = (const AAnimal& other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0; // pure virtual function - implementation not known
		std::string getType() const;
		//void setType(std::string type);
};
