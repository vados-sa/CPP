#include "PhoneBook.class.hpp"

int	main()
{
	PhoneBook phonebook; // phonebook is an object, instance of Phonebook (class), which has atributes and methods.

	std::string	command;
	bool running = true;

	while(running)
	{
		std::cout << "Please enter one of the three commands: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, command);
		
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			running = false;
		else
			std::cout << "Invalid command." << std::endl << std::endl;
	}	

	return 0;
}
