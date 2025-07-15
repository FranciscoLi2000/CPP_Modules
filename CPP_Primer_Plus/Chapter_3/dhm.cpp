
/* Write a program that asks the user to enter the number of seconds as an integer value
 *
 * (use type long, or, if available, long long)
 *
 * and that then displays the equivalent time in days, hours, minutes, and seconds.
 *
 * Use symbolic constants to represent the number of hours in the day, the number of minutes in an hour, and the number of seconds in a minute.
 *
 * The output should look like this:
 * Enter the number of seconds: 31600000
 * 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds */

#include <iostream>
using namespace std;

int	main(void)
{
	int	seconds;
	int	day;
	int	hour;
	int	minute;
	int	rest_scd;

	cout	<< "Enter the number of seconds: ";
	cin	>> seconds;
	day = ((seconds / 60) / 60) / 24;
	hour = ((seconds / 60) / 60) % 24;
	minute = (seconds / 60) % 60;
	rest_scd = seconds % 60;
	cout	<< day << " days, "
		<< hour << " hours, "
		<< minute << " minutes, "
		<< rest_scd << " seconds"
		<< endl;
	return (0);
}
