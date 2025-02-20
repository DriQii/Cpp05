#include "Intern.hpp"

Intern::Intern()
{
}
Intern::Intern(Intern &copy)
{
	(void)copy;
}
Intern::~Intern()
{
}
Intern& Intern::operator=(Intern &rhs)
{
	(void)rhs;
	return(*this);
}

AForm	*createPresidentForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm	*createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}



AForm	*Intern::makeForm(std::string type, std::string target)
{

	std::map<std::string, AForm *(*)(const std::string &)> map;
	std::map<std::string, AForm *(*)(const std::string &)>::iterator itMap;
	map["president form"] = createPresidentForm;
	map["shrubbery form"] = createShrubberyForm;
	map["robotomy form"] = createRobotomyForm;
	itMap = map.find(type);
	if (itMap != map.end())
		return map[type](target);
	std::cout << "Wrong form type : " << type << std::endl;
	return NULL;
}
