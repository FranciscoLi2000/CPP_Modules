#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: Form(other), _target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		Form::operator=(other);
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string const &PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void PresidentialPardonForm::executeAction(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
