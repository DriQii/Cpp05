#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b1("b1", 2);
	Bureaucrat b2("b2", 6);
	AForm form("Form1", 2, 152);
	AForm form2("Form2", 2, 6);

	std::cout << "\n" << form << std::endl;
	std::cout << form2 << "\n" << std::endl;
	form2.beSigned(b2);
	std::cout << form2 << "\n" << std::endl;

	form2.beSigned(b1);
	std::cout << form2 << "\n" <<std::endl;

	b2.signForm(form);
	std::cout << form << "\n" <<std::endl;
	b1.signForm(form);
	std::cout << form << "\n" <<std::endl;
}
