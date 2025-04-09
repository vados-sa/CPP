#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	void complain( std::string level );
};

#endif