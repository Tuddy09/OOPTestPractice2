#pragma once
#include "repository.h"

class Service
{
private:
	Repository repository;
public:
	Service(Repository repository) : repository(repository) {};
	std::string fileName;
	void generateEntriesService();
	void addAppliance(Appliance* appliance);
	std::vector<Appliance*> getAllAppliances();
	std::vector<Appliance*> getAllWithConsumedElectricityLessThan(double maxElectricity);
	void writeToFileAllAppliancesThatHaveAQuantityOfConsumedEnergyMoreThanGivenValueSortedById(std::string filename, double givenValue);
};