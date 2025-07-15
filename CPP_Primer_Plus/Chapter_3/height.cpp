
/* Write a short program that asks for your height in integer inches and then converts
 * your height to feet and inches.
 *
 * Have the program use the underscore character to indicate where to type the response.
 *
 * Also use a const symbolic constant to represent the conversion factor */

#include <iostream>

using namespace std;

int	main(void)
{
	const int	foot_to_inch = 12;
	int		height;

	cout	<< "Enter your height in integer inches: ";
	cin	>> height;
	cout	<< "Your height convert to "
		<< height / foot_to_inch
		<< " foot and "
		<< height % foot_to_inch
		<< " inches height" << endl;
	return (0);
}
