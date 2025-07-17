
/* William Wingate runs a pizza-analysis service. For each pizza, he needs to record
 * the following information:
 * n The name of the pizza company, which can consist of more than one word
 * n The diameter of the pizza
 * n The weight of the pizza
 * Devise a structure that can hold this information and write a program that uses a
 * structure variable of that type.The program should ask the user to enter each of the
 * preceding items of information, and then the program should display that informa-
 * tion. Use cin (or its methods) and cout. */

#include <iostream>

using namespace std;

struct pizza
{
	char	company_name[20];
	int		diameter;
	int		weight;
};

int	main(void)
{
	pizza	menu;

	cout	<< "Which company of pizza? ";
	cin.getline(menu.company_name, 20);
	cout	<< "The size of pizza in inches: ";
	cin	>> menu.diameter;
	cout	<< "The weight of the pizza in pounds: ";
	cin	>> menu.weight;

	cout	<< "The pizza, made by the company " << menu.company_name
		<< " has a diameter of " << menu.diameter << " inches "
		<< " and its weight is " << menu.weight << " pounds."
		<< endl;
	return (0);
}
