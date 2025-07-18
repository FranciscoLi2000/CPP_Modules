/* Write a program that asks the user to type in numbers.
 * After each entry, the program should report the cumulative sum of the entries to date.
 * The program should terminate when the user enters 0. */

#include <iostream>
using namespace std;

int	main(void)
{
	double	num;
	double	sum;

	num = sum = 0;
	do
	{
		cout	<< "Enter a number to add: ";
		cin	>> num;
		sum += num;
	}
	while (num != 0);
	cout	<< "Input end, sum = "
		<< sum
		<< endl;
	return (0);
}
