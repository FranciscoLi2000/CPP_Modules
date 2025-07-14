#include <iostream>
using namespace std;

double	transform(double cel)
{
	return (1.8 * cel + 32.0);
}

int	main(void)
{
	double	ce;
	double	res;

	cout	<< "Please enter a Celsius value: ";
	cin	>> ce;
	res = transform(ce);
	cout	<< ce
		<< " degrees Celsius is "
		<< res
		<< " degrees Fahrenheit"
		<< endl;
	return (0);
}
