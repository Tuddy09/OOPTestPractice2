#pragma once
#include "service.h"
#include <iostream>

class UI
{
private:
	Service service;
public:
	UI(Service service) : service(service) {};
	void run();
	void printMenu();
	~UI() {};
};