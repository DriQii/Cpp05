#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	//AForm form;

	Intern		intern;
	Bureaucrat	b1(1);
	AForm		*form;

	form = intern.makeForm("robotomy form", "test");
	AForm 		*form2(form);

	std::cout << *form << "\n" << std::endl;
	std::cout << *form2 << "\n" << std::endl;
	form2->beSigned(b1);
	form2->execute(b1);

	std::cout << std::endl;
	std::string	formTab[4] = {"robotomy form", "president form", "shrubbery form", "test form"};
	for(int i = 0; i < 4; i++)
	{
		form = intern.makeForm(formTab[i], "test");
		if (form)
			std::cout << *form << "\n" << std::endl;
		else
			std::cout << form << std::endl;
	}

}
