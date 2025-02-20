#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <map>

class Intern
{
	public :
		Intern();
		Intern(Intern &copy);
		~Intern();

		Intern& operator=(Intern &rhs);

		AForm	*makeForm(std::string type, std::string target);

};

#endif
