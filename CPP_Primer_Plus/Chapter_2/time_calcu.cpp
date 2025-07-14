#include <iostream>

using namespace std;

void	print_time(int h, int m)
{
	cout	<< "Time: "
		<< h
		<< ":"
		<< m
		<< endl;
}

int	main(void)
{
	int	hour;
	int	min;

	cout	<< "Enter the number of hours: ";
	cin	>> hour;
	cout	<< "Enter the number of minutes: ";
	cin	>> min;
	print_time(hour, min);
	return (0);
}
