/* Do Programming Exercise 5 but use a two-dimensional array to store input for 3 years of monthly sales.
 * Report the total sales for each individual year and for the combined years. */

#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	const string	month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dec"};

	int	sale_num[3][12];
	int	sum_per_year[3] = {0, 0, 0};
	int	total_sum;

	total_sum = 0;
	for (int j = 0; j < 3; j++)
	{
		cout	<< "Data of the year "
			<< j + 1 << ": " << endl;
		for (int i = 0; i < 12; i++)
		{
			cout	<< "Enter the number of "
				<< month[i]
				<< ": ";
			cin	>> sale_num[j][i];
		}
	}
	cout	<< "Input end" << endl;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 12; i++)
		{
			sum_per_year[j] += sale_num[j][i];
		}
		cout	<< "The year " << j
			<< " has "
			<< sum_per_year[j]
			<< endl;
		total_sum += sum_per_year[j];
	}
	cout	<< "Total three years' sale is "
		<< total_sum
		<< endl;
	return (0);
}
