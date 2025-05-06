//#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "=== Expected behavior ===" << std::endl;

	// const Animal* animal = new Animal(); // Cannot instantiate an abstract class
	const AAnimal* i = new Cat(); // This is also OK because a Cat IS an Animal
	const AAnimal* j = new Dog(); // This is also OK because a Dog IS an Animal
	// Cat* c = new Animal(); // This would NOT be ok because Animal IS NOT necessarely a Cat
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete i;
	delete j;

	return 0;
}