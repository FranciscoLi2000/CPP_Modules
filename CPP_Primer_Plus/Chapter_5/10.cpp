/* Write a program using nested loops that asks the user to enter a value for the number of rows to display.
 * It should then display that many rows of asterisks, with one asterisk in the first row, two in the second row, and so on.
 * For each row, the asterisks are preceded by the number of periods needed to make all the rows display a total number of characters equal to the number of rows.
 * A sample run would look like this:
 * Enter number of rows: 5
 * ....*
 * ...**
 * ..***
 * .****
 * ***** */

#include <iostream>
using namespace std;

int	main(void)
{
	int	row;
	int	i;
	int	j;
	int	k;

	cout	<< "Enter number of rows: ";
	cin	>> row;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < row - i - 1)
		{
			cout	<< ".";
			j++;
		}
		k = 0;
		while (k <= i)
		{
			cout	<< "*";
			k++;
		}
		cout	<< endl;
		i++;
	}
	return (0);
}
