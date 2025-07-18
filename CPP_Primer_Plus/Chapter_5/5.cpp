/* You sell the book C++ for Fools.
 * Write a program that has you enter a year’s worth of monthly sales (in terms of number of books, not of money).
 * The program should use a loop to prompt you by month, using an array of char * (or an array of string objects, if you prefer) initialized to the month strings and storing the input data in an array of int.
 * Then, the program should find the sum of the array contents and report the total sales for the year. */

#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	const string	month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dec"};

	int	sale_num[12];
	int	sum;

	sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout	<< "Enter the sale number of "
			<< month[i]
			<< ": ";
		cin	>> sale_num[i];
	}
	cout	<< "Input end" << endl;
	for (int i = 0; i < 12; i++)
	{
		sum += sale_num[i];
	}
	cout	<< "Total sale = "
		<< sum
		<< endl;
	return (0);
}
