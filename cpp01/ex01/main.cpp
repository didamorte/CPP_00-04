#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie* horde;
	int N = 5;

	std::cout << "Creating a horde..." << std::endl;
	horde = zombieHorde(N, "Zombie");
	
	std::cout << "\nAnnouncing all zombies:" << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	std::cout << "\nDeleting horde..." << std::endl;
	delete[] horde;
	
	std::cout << "\nEnd of program" << std::endl;
	return 0;
}