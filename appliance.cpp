#include "appliance.h"
#include <string>

using namespace std;
double Refrigerator::consumedElectricity()
{
	double consumed = 0.0;
	if (this->electricityUsageClass == "A")
		consumed = 30 * 3;
	else if (this->electricityUsageClass == "A+")
		consumed = 30 * 2.5;
	else if (this->electricityUsageClass == "A++")
		consumed = 30 * 2;
	if (this->hasFreezer == true)
		consumed += 20;
	return consumed;
}

string Refrigerator::toString()
{
	return this->id + " " + to_string(this->weight) + " " + this->electricityUsageClass + " " + to_string(this->hasFreezer);
}

double Dishwasher::consumedElectricity()
{
	double consumed = 0.0;
	consumed = this->washingCycleLength * this->consumedElectricityForOneHour;
	consumed *= 20;
	return consumed;
}

string Dishwasher::toString()
{
	return this->id + " " + to_string(this->weight) + " " + to_string(this->washingCycleLength) + " " + to_string(this->consumedElectricityForOneHour);
}
