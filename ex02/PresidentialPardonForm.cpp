#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{

}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
/* PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	return(*this);
} */
/* std::ostream& operator<<(std::ostream &lhs, AForm &rhs)
{

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
