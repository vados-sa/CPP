#include "Harl.hpp"

/*"DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.*/
void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup \
burger. I really do!" << std::endl << std::endl;
}

/*"INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.*/
void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

/*"WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.*/
void Harl::warning( void )
{
	std::cout << "[ WARNIG ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years, whereas you started working here just last month." << std::endl << std::endl;
}

/*"ERROR" level: These messages indicate that an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.*/
void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
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

	int i = 0;
	while(i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}
	
	switch (i)
	{
		case 0: // DEBUG
		case 1: // INFO
		case 2: // WARNING
		case 3: // ERROR
			for (int j = i; j < 4; j++)
				(this->*function_ptr[j])();
			return ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}