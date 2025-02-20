#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5, "presidential")
{
	std::cout << "Presidential form created with " <<  target << " for target" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute(), copy.getType())
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
/* PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	*this = rhs;
	return(*this);
} */

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	try {
		this->isExecutable(executor);
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	} catch (std::exception &e) {
		std::cout << executor.getName() << " can't execute " << this->getName() << " because "<< e.what() << std::endl;
	}
}
