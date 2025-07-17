
/* Do Programming Exercise 7 but use new to allocate a structure instead of declaring
 * a structure variable.Also have the program request the pizza diameter before it
 * requests the pizza company name. */

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
	pizza	*menu;

	menu = new pizza;

	cout	<< "Which company of pizza? ";
	cin.getline(menu->company_name, 20);
	cout	<< "The size of pizza in inches: ";
	cin	>> menu->diameter;
	cout	<< "The weight of the pizza in pounds: ";
	cin	>> menu->weight;

	cout	<< "The pizza, made by the company " << menu->company_name
		<< " has a diameter of " << menu->diameter << " inches "
		<< " and its weight is " << menu->weight << " pounds."
		<< endl;
	delete menu;
	return (0);
}
