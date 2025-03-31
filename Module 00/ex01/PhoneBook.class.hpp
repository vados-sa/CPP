#ifndef PHONE_BOOK_CLASS_H
#define PHONE_BOOK_CLASS_H

#include "Contact.class.hpp"
#include <sstream>
#include <stdlib.h>

class PhoneBook {
	private:
		Contact contact[8];
	public:
		void	add_contact();
		void	search_contact();
};

#endif