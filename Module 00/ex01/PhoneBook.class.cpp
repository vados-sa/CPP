#include <iostream>
#include <stdlib.h>
//#include "PhoneBook.class.hpp"
//#include "Contact.class.hpp"

// move to Phonebook.class.hpp later
class PhoneBook {
	private:
		Contact contact[8]; //atribute
	public:
		void	add_contact(); // method
		void	search_contact(); // method
};

/* If the user enters this command, they are prompted to input the information
of the new contact one field at a time. Once all the fields have been completed,
add the contact to the phonebook.
- The contact fields are: first name, last name, nickname, phone number, and
darkest secret. A saved contact can’t have empty fields.
- to add 9th contact, replace oldest one by the new one.
- dynamic alloc is forbiden.*/
void	PhoneBook::add_contact()
{
	std::cout << "add_contact function was called." << std::endl;

	/* std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_scret;
	
	std::cout << "To add a contact to the phonebook please provide: " << std::endl;
	std::cout << "First Name: " << std::endl;
	std::cin >> first_name; //std::getline(std::cin >> std::ws, first_name);
	std::cout << "Last Name: " << std::endl;
	std::cin >> last_name; //std::getline(std::cin >> std::ws, last_name);
	std::cout << "Nickname: " << std::endl;
	std::cin >> nickname; //std::getline(std::cin >> std::ws, nickname);
	std::cout << "Phone Number: " << std::endl;
	std::cin >> phone_number; //std::getline(std::cin >> std::ws, phone_number);
	std::cout << "Darkest Secret: " << std::endl;
	std::cin >> darkest_scret; //std::getline(std::cin >> std::ws, darkest_secret); */
}

/* Display a specific contact
- Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
- Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
- Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line. */
void	PhoneBook::search_contact(void)
{
	std::cout << "search_contact function was called." << std::endl;
}
