#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact {	
public:
	Contact(void);
	~Contact(void);
	
	std::string	first_name[100];
	std::string	last_name[100];
	std::string	nick_name[100];
	std::string	phone_number[100];
	std::string	darkest_secret[100];
	
};

#endif