#include "ui.h"

int main()
{
	Repository repository;
	Service service(repository);
	UI ui(service);
	ui.run();
	return 0;
}