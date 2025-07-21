/* Write a program that reads up to 10 donation values into an array of double. (Or, if
 * you prefer, use an array template object.) The program should terminate input on
 * non-numeric input. It should report the average of the numbers and also report
 * how many numbers in the array are larger than the average. */

#include <iostream>
#include <array>

using namespace std;

int	main(void)
{
	double	donations;
	array<double, 10>;

	cout	<< "Enter the number of donations: ";
	cin	>> donations;

	cout	<< "Average of donations: "
		<< average
		<<endl;
	cout	<< "The donations that are larger than the average has "
		<< count
		<< endl;
	return (0);
}
