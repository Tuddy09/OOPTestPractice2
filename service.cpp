#include "service.h"
#include <fstream>

void Service::generateEntriesService()
{
	this->repository.generateEntries();
}

void Service::addAppliance(Appliance* appliance)
{
	this->repository.addAppliance(appliance);
}

std::vector<Appliance*> Service::getAllAppliances()
{
	return this->repository.getAppliances();
}

std::vector<Appliance*> Service::getAllWithConsumedElectricityLessThan(double maxElectricity)
{
	std::vector<Appliance*> appliances = this->repository.getAppliances();
	std::vector<Appliance*> result;
	for (auto appliance : appliances)
	{
		if (appliance->consumedElectricity() < maxElectricity)
			result.push_back(appliance);
	}
	return result;
}

void Service::writeToFileAllAppliancesThatHaveAQuantityOfConsumedEnergyMoreThanGivenValueSortedById(std::string filename, double givenValue)
{
	this->fileName = filename;
	std::vector<Appliance*> appliances = this->repository.getAppliances();
	std::vector<Appliance*> result;
	for (auto appliance : appliances)
	{
		if (appliance->consumedElectricity() > givenValue)
			result.push_back(appliance);
	}
	// sort by id
	for (int i = 0; i < result.size() - 1; i++)
		for (int j = i + 1; j < result.size(); j++)
			if (result[i]->getId() > result[j]->getId())
			{
				Appliance* aux = result[i];
				result[i] = result[j];
				result[j] = aux;
			}
	// write to file
	std::ofstream file(this->fileName);
	for (auto appliance : result)
	{
		file << appliance->toString() << "\n";
	}
	file.close();
}
