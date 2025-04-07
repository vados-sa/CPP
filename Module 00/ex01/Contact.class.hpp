#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>
#include <iomanip>

class Contact {	
	private:
		std::string	first_name; // atribute
		std::string	last_name; // atribute
		std::string	nickname; // atribute
		std::string	phone_number; // atribute
		std::string	darkest_secret; // atribute
	
	public:
		bool set_contact();  // Method to set contact details
		bool is_set() const;
		bool unset();
		void truncate_and_or_display(std::string info);
		void display_contact() const;  // Method to display details
};

#endif