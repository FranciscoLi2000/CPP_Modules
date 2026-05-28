#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

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
	void	signForm(Form &form) const;
	void	executeForm(Form const &form) const;

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
