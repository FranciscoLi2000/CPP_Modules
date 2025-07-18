/* Write a program that requests the user to enter two integers.The program should
 * then calculate and report the sum of all the integers between and including the two
 * integers.At this point, assume that the smaller integer is entered first. For example, if
 * the user enters 2 and 9, the program should report that the sum of all the integers
 * from 2 through 9 is 44. */

#include <iostream>
using namespace std;

int	main(void)
{
	int	num1;
	int	num2;
	int	i;
	int	sum;

	cout	<< "Enter the first integer: ";
	cin	>> num1;
	cout	<< "Enter the second integer: ";
	cin	>> num2;

	sum = 0;
	for (i = num1; i <= num2; i++)
		sum += i;
	cout	<< "The sum is "
		<< sum << endl;
	return (0);
}
