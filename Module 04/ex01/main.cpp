//#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void deepCopyTests()
{
	std::cout << "\n=== Deep Copy Tests ===" << std::endl << std::endl;	
	
	std::cout << "\n=== Dogs ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Chase the ball");
    std::cout << "Dog1 Brain Idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	Dog dog2(dog1);
	std::cout << "Dog2 Brain Idea[0] (after copy): " << dog2.getBrain()->getIdea(0) << std::endl;
	dog2.getBrain()->setIdea(0, "Bark at the mailman");
	std::cout << "Dog1 Brain Idea[0] (after modifying Dog2): " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 Brain Idea[0] (after modifying Dog2): " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	Dog dog3;
	dog3.getBrain()->setIdea(0, "Run after the car");
    std::cout << "Dog3 Brain Idea[0] (before assigment): " << dog3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	dog3 = dog1;
	std::cout << "Dog1 Brain Idea[0] : " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog3 Brain Idea[0] (after assignment): " << dog3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "\n=== Cats ===" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea(0, "Climb the tree");
    std::cout << "Cat1 Brain Idea[0]: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	Cat cat2(cat1);
	std::cout << "Cat2 Brain Idea[0] (after copy): " << cat2.getBrain()->getIdea(0) << std::endl;
	cat2.getBrain()->setIdea(0, "Sleep on the couch");
	std::cout << "Cat1 Brain Idea[0] (after modifying Cat2): " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 Brain Idea[0] (after modifying Cat2): " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	Cat cat3;
	cat3.getBrain()->setIdea(0, "Sleep on rug");
    std::cout << "Cat3 Brain Idea[0] (before assigment): " << cat3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	cat3 = cat1;
	std::cout << "Cat1 Brain Idea[0] : " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat3 Brain Idea[0] (after assignment): " << cat3.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
}

int main()
{
	//const Animal* j = new Dog();
	//const Animal* i = new Cat();
	//delete j; //should not create a leak
	//delete i;
	//std::cout << std::endl;
	
	std::cout << "=== Array of Animals ===" << std::endl << std::endl;
	
	int n = 4;
	const Animal* animals[n];

	for(int i = 0; i < n; i++)
	{
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	for(int i = 0; i < n; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	deepCopyTests();

	return 0;
}