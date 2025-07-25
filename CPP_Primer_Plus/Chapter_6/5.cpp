/* 5. The Kingdom of Neutronia, where the unit of currency is the tvarp, has the following income tax code:
 * First 5,000 tvarps: 0% tax
 * Next 10,000 tvarps: 10% tax
 * Next 20,000 tvarps: 15% tax
 * Tvarps after 35,000: 20% tax
 * For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 × 0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.
 * Write a program that uses a loop to solicit incomes and to report tax owed.
 * The loop should terminate when the user enters a negative number or non-numeric input. */

#include <iostream>

using namespace std;

int	main(void)
{
	double	income;
	double	tax;

	cout	<< "Please enter your earnings: ";
	while ((cin >> income) && (income >= 0))
	{
		if (income <= 5000)
			tax = 0.0;
		else if (income <= 15000)
			tax = (income - 5000) * 0.1;
		else if (income <= 35000)
			tax = 10000 * 0.1 + (income - 15000) * 0.15;
		else
			tax = 10000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
		cout	<< "Tax = "
			<< tax
			<< endl;
		cout	<< "Enter your income: ";
	}
	return (0);
}
