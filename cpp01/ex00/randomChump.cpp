#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

void randomChump(std::string name)
{
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}

