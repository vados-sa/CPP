#ifndef PHONE_BOOK_CLASS_H
#define PHONE_BOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook {

	public:
	
	PhoneBook(void); //member function with the same name as its class must be a constructor
	~PhoneBook(void);

	void	add_contact();
	void	search_contact();
};

#endif