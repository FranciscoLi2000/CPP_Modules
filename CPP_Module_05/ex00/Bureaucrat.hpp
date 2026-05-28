#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

/*
 * Bureaucrat is the smallest piece of the module 05 office machine.
 * It teaches strong invariants: the grade must always stay between 1 and 150.
 */

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat(void);

	std::string const &getName(void) const;
	int	getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
