#pragma once
#include "appliance.h"
#include <vector>

class Repository
{
private:
	vector<Appliance*> appliances;
public:
	Repository() {};
	void generateEntries();
	void addAppliance(Appliance* appliance);
	vector<Appliance*> getAppliances();
	~Repository();
};