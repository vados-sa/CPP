#include "Contact.class.hpp"

bool	Contact::unset()
{
	if (first_name.empty() == false)
		first_name.clear();
	if (last_name.empty() == false)
		last_name.clear();
	if (nickname.empty() == false)
		nickname.clear();
	if (phone_number.empty() == false)
		phone_number.clear();
	if (darkest_secret.empty() == false)
		darkest_secret.clear();
	return false;
}

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return ""; // String is all whitespace
    }

    return str.substr(start, end - start + 1);
}

bool	Contact::set_contact()
{
	std::cout << "Enter First Name: " << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
	std::getline(std::cin, first_name); // it directly modifies the existing class attribute.
	first_name = trim(first_name);
	if (first_name.empty())
		return unset(); // unset fucntion returns false

	std::cout << "Enter Last Name: " << std::endl;
	std::getline(std::cin, last_name);
	last_name = trim(last_name);
	if (last_name.empty())
		return unset(); // unset fucntion returns false

	std::cout << "Enter Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	nickname = trim(nickname);
	if (nickname.empty())
		return unset(); // unset fucntion returns false

	std::cout << "Enter Phone Number: " << std::endl;
	std::getline(std::cin, phone_number);
	phone_number = trim(phone_number);
	if (phone_number.empty())
		return unset(); // unset fucntion returns false

	std::cout << "Enter Darkest Secret: " << std::endl;
	std::getline(std::cin, darkest_secret);
	darkest_secret = trim(darkest_secret);
	if (darkest_secret.empty())
		return unset(); // unset fucntion returns false

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
		std::cout << std::setw(10);
	/* {
		while (info_to_display.length() < 10)
            info_to_display = " " + info_to_display;
	} */
	
	std::cout << info_to_display;
}
