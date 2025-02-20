#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	//AForm form;
	ShrubberyCreationForm	home("home");
	RobotomyRequestForm		robot("robot");
	PresidentialPardonForm	president("president");
	Bureaucrat				b1("b1", 1);
	Bureaucrat				b2("b2", 100);


	b1.signForm(president);
	b2.executeForm(president);
	b1.executeForm(president);
	b2.signForm(home);
	b2.signForm(robot);
	b2.signForm(president);
	b1.signForm(home);
	b1.signForm(robot);
	b1.signForm(president);
	home.execute(b2);
	home.execute(b1);
	robot.execute(b2);
	robot.execute(b1);
	president.execute(b2);
	president.execute(b1);
}
