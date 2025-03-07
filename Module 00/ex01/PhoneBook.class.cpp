#include <iostream>
#include <stdlib.h>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

// to add 9th contact, replace oldest one by the new one.
	// dynamic alloc is forbiden.

void	PhoneBook::add_contact(std::string contacts[8][5])
{
	if (contacts[8])
	{
		// delete 1st contact, add new one
	}
	else
	{
		for (int i = 0; contacts[i]; i++)
			;
	}
}

void	PhoneBook::search_contact(void)
{

}

PhoneBook::PhoneBook(void)
{
	
}