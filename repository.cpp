#include "repository.h"

void Repository::generateEntries()
{
	Refrigerator* refrigerator1 = new Refrigerator("Beko", 100, "A+", true);
	Refrigerator* refrigerator2 = new Refrigerator("Samsung", 500, "A", false);
	Dishwasher* dishwasher1 = new Dishwasher("Bosch" , 250, 3, 20);
	this->appliances.push_back(refrigerator1);
	this->appliances.push_back(refrigerator2);
	this->appliances.push_back(dishwasher1);
}

void Repository::addAppliance(Appliance* appliance)
{
	this->appliances.push_back(appliance);
}

vector<Appliance*> Repository::getAppliances()
{
	return this->appliances;
}

Repository::~Repository()
{
	for (auto appliance : this->appliances)
		delete appliance;
}