#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

/*
 * This exercise connects Bureaucrat and Form through signing rules.
 */
int	main(void)
{
	Bureaucrat high("HighRank", 1);
	Bureaucrat mid("MidRank", 75);
	Form paper("Paperwork", 50, 25);
	Form easy("EasyForm", 100, 100);

	std::cout << paper << std::endl;
	high.signForm(paper);
	mid.signForm(paper);
	mid.signForm(easy);
	std::cout << easy << std::endl;

	return (0);
}
