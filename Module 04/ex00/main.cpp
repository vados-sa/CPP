//#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Expected behavior ===" << std::endl;

	const Animal* animal = new Animal(); // This is OK, obviously, Animal IS an Animal
	const Animal* i = new Cat(); // This is also OK because a Cat IS an Animal
	const Animal* j = new Dog(); // This is also OK because a Dog IS an Animal
	// Cat* c = new Animal(); // This would NOT be ok because Animal IS NOT necessarely a Cat
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	animal->makeSound();

	delete animal;
	delete i;
	delete j;
	
	std::cout << std::endl << "=== Wrong Animal behavior ===" << std::endl;

	const WrongAnimal* wcat = new WrongCat();
	std::cout << wcat->getType() << " " << std::endl;
	wcat->makeSound(); // will output WrongAnimal sound

	delete wcat; // Only WrongAnimal's destructor is called. This may result in resource leakage.

	return 0;
}