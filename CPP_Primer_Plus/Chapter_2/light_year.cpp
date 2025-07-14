#include <iostream>

using namespace std;

int	calc(int ly)
{
	return (ly * 63240);
}

int	main(void)
{
	int	light;
	int	res;

	cout	<< "Enter the number of light years: ";
	cin	>> light;
	cout	<< light;
	cout	<< " light years = ";
	res = calc(light);
	cout	<< res
		<< " astronomical units"
		<< endl;
	return (0);
}
