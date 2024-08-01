#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat tony("Tony", 18);
	Bureaucrat test("Test", -10);
	Bureaucrat copy(tony);
	Bureaucrat def;

	def = test;

	std::cout << def << std::endl;
	std::cout << copy << std::endl;
	while(copy.getGrade()  > 1)
	{
		copy.increment();
		std::cout << copy << std::endl;
	}
	copy.increment();
	std::cout << copy << std::endl;
	while(copy.getGrade() < 150)
	{
		copy.decrement();
		std::cout << copy << std::endl;
	}
	copy.decrement();
	std::cout << copy << std::endl;
}
