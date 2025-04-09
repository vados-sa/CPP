#include "Harl.hpp"

/*"DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.*/
void Harl::debug( void )
{
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup \
burger. I really do!" << std::endl;
}

/*"INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.*/
void Harl::info( void )
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

/*"WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.*/
void Harl::warning( void )
{
	std::cout << "WARNIG: I think I deserve to have some extra bacon for free. I’ve been coming for \
years, whereas you started working here just last month." << std::endl;
}

/*"ERROR" level: These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.*/
void Harl::error( void )
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	// Declare a array of pointers to member functions.
	void (Harl::*function_ptr[])(void) = {
		&Harl::debug, // assign fucntion debug to function_ptrs[0].
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // array of levels

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*function_ptr[i])(); // dynamic fucntion call
			return ;
		}
	}

	std::cout << "Invalid level!" << std::endl;
}