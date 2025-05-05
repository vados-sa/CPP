#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	type = other.type;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Mee-owww!" << std::endl;
}