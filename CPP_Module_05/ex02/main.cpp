#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*
 * This exercise teaches execution through an abstract base class.
 */
int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);
	Bureaucrat intern("Intern", 150);
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	intern.signForm(shrub);
	boss.signForm(shrub);
	boss.signForm(robo);
	boss.signForm(pardon);

	intern.executeForm(shrub);
	boss.executeForm(shrub);
	boss.executeForm(robo);
	boss.executeForm(pardon);

	return (0);
}
