#include <iostream>
#include "PhoneBook.class.hpp"
//#include "Contact.class.hpp"

int	main()
{
	PhoneBook phonebook;

	std::string	command;

	while(1)
	{
		std::cout << "Please enter one of the three commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> command;
		
		if (!command.compare("ADD"))
			phonebook.add_contact();
			//std::cout << "calling function to add" << std::endl;
		else if (!command.compare("SEARCH"))
			phonebook.search_contact();
			//std::cout << "calling function to search" << std::endl;
		else if (!command.compare("EXIT"))
			exit(0);
	}	

	return 0;
}