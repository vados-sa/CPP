#include "PhoneBook.class.hpp"

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
