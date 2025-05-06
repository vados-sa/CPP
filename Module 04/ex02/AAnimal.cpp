#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type("Base AAnimal")
{
	std::cout << "AAnimal Default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
	: type(other.type)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& other)
{
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called." << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

/* void AAnimal::setType(std::string type)
{
	this->type = type;
} */