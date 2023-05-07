#pragma once
#include <string>

using namespace std;
class Appliance
{
protected:
	string id;
	double weight;
public:
	string getId() { return this->id; }
	virtual double consumedElectricity() = 0;
	virtual string toString() = 0;
	virtual ~Appliance() {};
};

class Refrigerator : public Appliance
{
private:
	string electricityUsageClass;
	bool hasFreezer;
public:
	Refrigerator(string id, double weight, string electricityUsageClass, bool hasFreezer)
	{
		this->id = id;
		this->weight = weight;
		this->electricityUsageClass = electricityUsageClass;
		this->hasFreezer = hasFreezer;
	}
	double consumedElectricity() override;
	string toString() override;
	~Refrigerator() {};
};

class Dishwasher : public Appliance
{
private:
	double washingCycleLength;
	double consumedElectricityForOneHour;
public:
	Dishwasher(string id, double weight, double washingCycleLength, double consumedElectricityForOneHour)
	{
		this->id = id;
		this->weight = weight;
		this->washingCycleLength = washingCycleLength;
		this->consumedElectricityForOneHour = consumedElectricityForOneHour;
	}
	double consumedElectricity() override;
	string toString() override;
	~Dishwasher() {};
};