#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form : public Bureaucrat{
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeSign;
		const int	gradeExec;

	public:
		//OCF
		//getters

		void beSigned(Bureaucrat Bureaucrat);
};