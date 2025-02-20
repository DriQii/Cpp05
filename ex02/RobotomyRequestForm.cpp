#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{

}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute())
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
/* RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
	return(*this);
} */
/* std::ostream& operator<<(std::ostream &lhs, AForm &rhs)
{

} */

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	try {
		this->isExecutable(executor);
		std::srand(time(NULL));
		for (int i = 0; i < 5 ; i++)
		{
			usleep(250000);
			std::cout << "Brrrrrrrrrrrrrrrrrrr !!!!" << std::endl;
		}
				std::cout << ((std::rand() % 2) ? this->getName() + " has been robotomized successfully !": "Robotomizationing fail broski !") << std::endl;
	} catch (std::exception &e) {
		std::cout << executor.getName() << " can't execute " << this->getName() << " because "<< e.what() << std::endl;
	}
}
