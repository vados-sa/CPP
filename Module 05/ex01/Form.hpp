#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const		std::string name;
		bool		isSigned;
		const int	gradeSign;
		const int	gradeExec;

	public:
		Form();
		Form(std::string name, bool isSigned, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		
		std::string getName() const;
		bool getSign() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(Bureaucrat Bureaucrat);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);
