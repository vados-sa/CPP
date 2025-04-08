#include "PhoneBook.class.hpp"

static std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return ""; // String is all whitespace
    }

    return str.substr(start, end - start + 1);
}

void	PhoneBook::add_contact()
{
	static int contact_count = 0;
	int	index = contact_count % 8;

	if (contact_count >= 8)
		std::cout << "Phonebook is full. Replacing oldest contact...\n";
	if (contact[index].set_contact() == true) // This calls the set_contact() method on that specific Contact object.
		contact_count++;
	else
		std::cout << "A saved contact can't have empty fields. Please try again.\n"; // if so, everything that has previously being added has to be cleaned.
}

int PhoneBook::get_contact_index() const
{
	while (true)
	{
		int index;
		std::string input;
		std::getline(std::cin, input);
		input = trim(input);
		try {
			std::stringstream ss(input); // parse the string input into an integer.
			if (!(ss >> index) || !ss.eof()) // If an integer wasn't extracted OR it was but the entire string wasn't consumed.
    		throw std::invalid_argument("Invalid input.");
			if (index < 0 || index >= 8 || !contact[index].is_set())
            throw std::out_of_range("Index is invalid or out of range."); // costume exception type with 'throw'
			return index;

		} catch (const std::invalid_argument &e) {
			std::cout << e.what() << " Please try again: ";
		} catch (const std::out_of_range &e) {
			std::cout << e.what() << " Please try again: ";
		} catch (const std::exception &e) {
			std::cout << "Standard exception: " << e.what() << std::endl;
		} catch (...) {
			std::cout << "An unexpected error occurred." << std::endl;
		}
	}
}

void	PhoneBook::search_contact(void)
{
	if (contact[0].is_set() == false)
	{
		std::cout << "The Phonebook is empty, please add a contact first." << std::endl;
		return ;
	}

	for (int i = 0; i < 8 && contact[i].is_set(); i++)
	{
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";
		contact[i].truncate_and_or_display("fn");
		std::cout << "|";
		contact[i].truncate_and_or_display("ln");
		std::cout << "|";
		contact[i].truncate_and_or_display("nn");
		std::cout << std::endl << std::endl;
	}

    std::cout << "Please enter the index of the contact you want: ";
	int index = get_contact_index();
	contact[index].display_contact();
}
