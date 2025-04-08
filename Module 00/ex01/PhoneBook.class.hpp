#ifndef PHONE_BOOK_CLASS_H
#define PHONE_BOOK_CLASS_H

#include "Contact.class.hpp"
#include <sstream>
#include <stdlib.h>

class PhoneBook {
	private:
		Contact contact[8]; // Each element in this array is an instance of the Contact class.
	public:
		void	add_contact();
		void	search_contact();
		int		get_contact_index() const;
};

#endif