#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class Form;

class Intern
{
public:
	Intern(void);
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern(void);

	Form	*makeForm(std::string const &formName, std::string const &target);

private:
	Form	*makeShrubbery(std::string const &target) const;
	Form	*makeRobotomy(std::string const &target) const;
	Form	*makePresidential(std::string const &target) const;
};

#endif
