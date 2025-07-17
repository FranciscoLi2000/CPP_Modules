
/* Write a program that requests the user to enter three times for the 40-yd dash (or
 * 40-meter, if you prefer) and then displays the times and the average. Use an array
 * object to hold the data. (Use a built-in array if array is not available.) */

#include <iostream>
#include <array>

using namespace std;

int	main(void)
{
	array<float, 3>	record_list;

	cout	<< "Enter the three times of 40-meter result: " << endl;
	cout	<< "First: ";
	cin	>> record_list[0];
	cout	<< "Second: ";
	cin	>> record_list[1];
	cout	<< "Third: ";
	cin	>> record_list[2];

	cout	<< "List:" << endl
		<< "First: " << record_list[0] << endl
		<< "Second: " << record_list[1] << endl
		<< "Third: " << record_list[2] << endl
		<< "Average: " << (record_list[0] + record_list[1] + record_list[2]) / 3 << endl;

	return (0);
}
