/* Write a program that reads up to 10 donation values into an array of double. (Or, if
 * you prefer, use an array template object.) The program should terminate input on
 * non-numeric input. It should report the average of the numbers and also report
 * how many numbers in the array are larger than the average. */

#include <iostream>
#include <array>

using namespace std;

int	main(void)
{
	double	input;
	array<double, 10>	donation;
	int	count;
	double	sum;
	double	average;

	count = 0;
	sum = 0.0;
	cout << "Enter 10 double values: ";
	while ((cin >> input))
	{
		donation[count++] = input;
		if (count == 10)
			break ;
		cout << "Enter another value: ";
	}
	int i = 0;
	while (i < count)
	{
		sum += donation[i];
		i++;
	}
	cout << "Average: "
		<< sum / count
		<< endl;
	int	big = 0;
	for (int i = 0; i < count; i++)
	{
		if (donation[i] > (sum / count))
			big++;
	}
	cout << "There is "
		<< big
		<< " values bigger than the average."
		<< endl;
	return (0);
}
