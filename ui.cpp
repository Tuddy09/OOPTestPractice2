#include "ui.h"
#include <iostream>
#include <string>

using namespace std;
void UI::run()
{
	this->service.generateEntriesService();
	while (true)
	{
		string command;
		this->printMenu();
		getline(cin, command);
		if (command == "1")
		{
			cout<< "Enter the type of appliance (refrigerator/dishwasher): ";
			string type;
			getline(cin, type);
			if (type == "refrigerator")
			{
				string id;
				cout<<"Enter the id: ";
				getline(cin, id);
				double weight;
				cout<<"Enter the weight: ";
				cin>>weight;
				cin.ignore();
				string electricityUsageClass;
				cout<<"Enter the electricity usage class: ";
				getline(cin, electricityUsageClass);
				bool hasFreezer;
				cout<<"Enter if it has a freezer (true/false): ";
				cin>>hasFreezer;
				cin.ignore();
				Refrigerator* refrigerator = new Refrigerator(id, weight, electricityUsageClass, hasFreezer);
				this->service.addAppliance(refrigerator);
			}
			else if (type == "dishwasher")
			{
				string id;
				cout<<"Enter the id: ";
				getline(cin, id);
				double weight;
				cout<<"Enter the weight: ";
				cin>>weight;
				cin.ignore();
				double washingCycleLength;
				cout<<"Enter the washing cycle length: ";
				cin>>washingCycleLength;
				cin.ignore();
				double consumedElectricityForOneHour;
				cout<<"Enter the consumed electricity for one hour: ";
				cin>>consumedElectricityForOneHour;
				cin.ignore();
				Dishwasher* dishwasher = new Dishwasher(id, weight, washingCycleLength, consumedElectricityForOneHour);
				this->service.addAppliance(dishwasher);
			}
			else
				cout<<"Invalid type"<<endl;
		}
		else if (command == "2")
		{
			vector<Appliance*> appliances = this->service.getAllAppliances();
			for (auto appliance : appliances)
				cout<<appliance->toString()<<endl;
		}
		else if (command == "3")
		{
			double electricity;
			cout<<"Enter the electricity: ";
			cin>>electricity;
			cin.ignore();
			vector<Appliance*> appliances = this->service.getAllWithConsumedElectricityLessThan(electricity);
			for (auto appliance : appliances)
				cout<<appliance->toString()<<endl;
		}
		else if (command == "4")
		{
			double electricity;
			cout<<"Enter the electricity: ";
			cin>>electricity;
			cin.ignore();
			string filename;
			cout<<"Enter the filename: ";
			getline(cin, filename);
			this->service.writeToFileAllAppliancesThatHaveAQuantityOfConsumedEnergyMoreThanGivenValueSortedById(filename, electricity);
		}
		else if (command == "0")
			break;
		else
			cout<<"Invalid command"<<endl;
	}
}

void UI::printMenu()
{
	cout<<"1. Add appliance"<<endl;
	cout<<"2. Show appliances"<<endl;
	cout<<"3. Show appliances with electricitu less than given value"<<endl;
	cout<<"4. Save to file all apliances that have a quantity of consumed electricity more than a given value sorted by id"<<endl;
	cout<<"0. Exit"<<endl;

}
