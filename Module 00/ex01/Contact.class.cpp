#include "Contact.class.hpp"

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

bool	Contact::is_set() const
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
