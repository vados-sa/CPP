#include <iostream>
#include "PhoneBook.class.hpp"
//#include "Contact.class.hpp"

int	main()
{
	PhoneBook phonebook; // phonebook is an object, instance of Phonebook (class), which has atributes and methods.

	std::string	command;

	while(1)
	{
		std::cout << "Please enter one of the three commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> command;
		
		if (!command.compare("ADD"))
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search_contact();
		else if (!command.compare("EXIT"))
			exit(0);
	}	

	return 0;
}