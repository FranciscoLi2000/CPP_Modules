#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

namespace
{
	struct FormFactory
	{
		const char	*name;
		Form		*(Intern::*creator)(std::string const &target) const;
	};
}

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Form *Intern::makeShrubbery(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomy(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidential(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

/*
 * The factory table avoids long if/else chains and keeps the mapping explicit.
 */
Form *Intern::makeForm(std::string const &formName, std::string const &target)
{
	static const FormFactory factories[] = {
		{"shrubbery creation", &Intern::makeShrubbery},
		{"robotomy request", &Intern::makeRobotomy},
		{"presidential pardon", &Intern::makePresidential}
	};
	int	i;

	for (i = 0; i < 3; ++i)
	{
		if (formName == factories[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*factories[i].creator)(target));
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
