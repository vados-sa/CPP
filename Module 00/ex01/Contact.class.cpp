#include <iostream>
//#include "Contact.class.hpp"

// move to Contact.class.hpp later
class Contact {	
	private:
		std::string	first_name; // atribute
		std::string	last_name; // atribute
		std::string	nickname; // atribute
		std::string	phone_number; // atribute
		std::string	darkest_secret; // atribute
	
	public:
		void set_contact();  // Method to set contact details
		void display_contact() const;  // Method to display details
};

