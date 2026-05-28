#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

/*
 * The grade is the invariant gatekeeper, so the constructor validates it first.
 */
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const &Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
