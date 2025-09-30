#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
	std::cout << "Intern Default Constructor." << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern Copy constructor." << std::endl;
}

Intern& Intern::operator = (const Intern& other) {
	(void)other;
	std::cout << "Intern Copy assignment operator." << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Destructor called for Intern." << std::endl;
}

static std::string toLowerStr(const std::string& s) {
    std::string r;
    r.reserve(s.size());
    for (std::string::size_type i = 0; i < s.size(); ++i)
        r.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(s[i]))));
    return r;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {

	if (formName.empty()) {
		std::cout << "Missing form name.\n";
		throw Intern::UnknownFile();
	}

    const char* names[6] = {
        "shrubbery creation",
		"shrubberycreationform",
        "robotomy request",
		"robotomyrequestform",
        "presidential pardon",
		"presidentialpardonform"
    };

    const std::string key = toLowerStr(formName);
    int idx = -1;
    for (int i = 0; i < 6; ++i) {
        if (key == names[i]) { idx = i; break; }
    }
    if (idx == -1)
        throw Intern::UnknownFile();

    AForm* form = NULL;
    switch (idx) {
        case 0: case 1: form = new ShrubberyCreationForm(formTarget); break;
        case 2: case 3: form = new RobotomyRequestForm(formTarget); break;
        case 4: case 5: form = new PresidentialPardonForm(formTarget); break;
    }

    std::cout << "Intern creates " << names[idx] << "." << std::endl;
    return form;
}

const char* Intern::UnknownFile::what() const  throw()
{
	return "Unknown File.";
}
