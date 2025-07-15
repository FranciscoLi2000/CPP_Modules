
/* Write a program that asks the user to enter a latitude in degrees, minutes, and seconds and that then displays the latitude in decimal format.
 *
 * There are 60 seconds of arc to a minute and 60 minutes of arc to a degree; represent these values with symbolic constants.
 *
 * You should use a separate variable for each input value.
 *
 * A sample run should look like this:
 * Enter a latitude in degrees, minutes, and seconds:
 * First, enter the degrees: 37
 * Next, enter the minutes of arc: 51
 * Finally, enter the seconds of arc: 19
 * 37 degrees, 51 minutes, 19 seconds = 37.8553 degrees */

#include <iostream>
using namespace std;

const int	DEGREE_TO_MINUTE = 60;
const int	DEGREE_TO_SECOND = 3600;

int	main(void)
{
	int	degrees;
	int	minutes;
	int	seconds;
	double	result;

	cout	<< "Enter a latitude in degrees, minutes and seconds:" << endl;
	cout	<< "First, enter the degrees: ";
	cin	>> degrees;
	cout	<< "Next, enter the minutes of arc: ";
	cin	>> minutes;
	cout	<< "Finally, enter the seconds of arc: ";
	cin	>> seconds;

	result = degrees + (double)minutes / DEGREE_TO_MINUTE + (double)seconds / DEGREE_TO_SECOND;
	cout	<< degrees << " degrees, "
		<< minutes << " minutes, "
		<< seconds << " seconds = "
		<< result << " degrees"
		<< endl;
	return (0);
}
