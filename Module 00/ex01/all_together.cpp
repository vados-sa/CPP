#include <iostream>
#include <stdlib.h>

class Contact {	
	private:
		std::string	first_name; // atribute
		std::string	last_name; // atribute
		std::string	nickname; // atribute
		std::string	phone_number; // atribute
		std::string	darkest_secret; // atribute
	
	public:
		bool set_contact();  // Method to set contact details
		bool is_set();
		void truncate_and_or_display(std::string info);
		void display_contact() const;  // Method to display details
};

class PhoneBook {
	private:
		Contact contact[8];
	public:
		void	add_contact();
		void	search_contact();
};



bool	Contact::set_contact()
{
	std::cout << "Enter First Name: " << std::endl;
	std::getline(std::cin >> std::ws, first_name); // it directly modifies the existing class attribute. 
	if (first_name.empty())
		return false;

	std::cout << "Enter Last Name: " << std::endl;
	std::getline(std::cin >> std::ws, last_name);
	if (last_name.empty())
		return false;

	std::cout << "Enter Nickname: " << std::endl;
	std::getline(std::cin >> std::ws, nickname);
	if (nickname.empty())
		return false;

	std::cout << "Enter Phone Number: " << std::endl;
	std::getline(std::cin >> std::ws, phone_number);
	if (phone_number.empty())
		return false;

	std::cout << "Enter Darkest Secret: " << std::endl;
	std::getline(std::cin >> std::ws, darkest_secret);
	if (darkest_secret.empty())
		return false;

	std::cout << "Contact added!" << std::endl;
	return true;
}

void	Contact::display_contact() const
{
	std::cout << std::endl;
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
	std::cout << std::endl;
}

bool	Contact::is_set()
{
	if (first_name.empty())
		return false;
	return true;
}

void	Contact::truncate_and_or_display(std::string info_code)
{
	std::string	info_to_display;

	if (info_code.compare("fn") == 0)
		info_to_display = first_name;
	else if (info_code.compare("ln") == 0)
		info_to_display = last_name;
	else if (info_code.compare("nn") == 0)
		info_to_display = nickname;
	if (info_to_display.length() > 10)
	{
		info_to_display.resize(9);
		info_to_display.insert(9, ".");	
	}
	else
	{
		while (info_to_display.length() < 10)
            info_to_display = " " + info_to_display;
	}
	
	std::cout << info_to_display;
}

void	PhoneBook::add_contact() // not working well, 9th contact is added somehow.
{
	static int contact_count = 0;
	int	index = contact_count % 8; // ensures old contacts are replaced in order.
    std::cout << "Adding contact at index: " << index << " (contact count: " << contact_count << ")\n";

	if (contact_count >= 8)
		std::cout << "Phonebook is full. Replacing oldest contact...\n";
	if (contact[index].set_contact() == true) // This calls the set_contact() method on that specific Contact object.
		contact_count++;
	else
		std::cout << "Invalid input. Please try again.\n";
}

void	PhoneBook::search_contact(void) // not working well, last_name is being printed first, first_name comes second and thrid
{
	if (contact[0].is_set() == false)
	{
		std::cout << "The Phonebook is empty, please add a contact first." << std::endl;
		return ;
	}

	for (int i = 0; i < 8 && contact[i].is_set(); i++)
	{
		std::cout << "         " << i << "|";
		contact[i].truncate_and_or_display("fn");
		std::cout << "|";
		contact[i].truncate_and_or_display("ln");
		std::cout << "|";
		contact[i].truncate_and_or_display("nn");
		std::cout << std::endl << std::endl;
	}

	int index;
    std::string input;
    std::cout << "Please enter the index of the contact you want: ";
    std::cin >> input;
    try {
        index = std::stoi(input);
        if (index < 0 || index >= 8 || !contact[index].is_set()) {
            throw std::out_of_range("Index is invalid or out of range."); // costume exception type with 'throw'
        }
        contact[index].display_contact();
    } catch (const std::invalid_argument &e) {
        std::cout << "Invalid input. Please try again." << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << e.what() << " Please try again." << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
	} catch (...) {
        std::cout << "An unexpected error occurred." << std::endl;
    }
}

int	main()
{
	PhoneBook phonebook; // phonebook is an object, instance of Phonebook (class), which has atributes and methods.

	std::string	command;
	bool running = true;

	while(running)
	{
		std::cout << "Please enter one of the three commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> command;
		
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			running = false;
		else
			std::cout << "Invalid command." << std::endl;
	}	

	return 0;
}
