
/* Write a program that asks you to enter an automobile gasoline consumption figure
 * in the European style (liters per 100 kilometers) and converts to the U.S. style of
 * miles per gallon. Note that in addition to using different units of measurement, the
 * U.S. approach (distance / fuel) is the inverse of the European approach (fuel / dis-
 * tance). Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.Thus, 19
 * mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km */

#include <iostream>
using namespace std;

const double	GALLON_TO_LITRE = 3.875;
const double	HKM_TO_MILE = 62.14;

int	main(void)
{
	double	fuel_consume_euro;
	double	fuel_consume_us;

	cout	<< "Enter the fuel consume in Europe (L/100km): ";
	cin	>> fuel_consume_euro;
	fuel_consume_us = GALLON_TO_LITRE * HKM_TO_MILE / fuel_consume_euro;
	cout	<< "The fuel consume in the US is "
		<< fuel_consume_us
		<< " miles/gallon"
		<< endl;
	return (0);
}
