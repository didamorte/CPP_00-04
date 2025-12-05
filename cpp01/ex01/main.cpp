#include "Zombie.hpp"
#include <iostream>
#include <iomanip>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie* heapZombie;

	std::cout << "Creating heap zombie..." << std::endl;
	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	
	std::cout << "\nCreating stack zombie..." << std::endl;
	randomChump("StackZombie");
	
	std::cout << "\nDeleting heap zombie..." << std::endl;
	delete heapZombie;
	
	std::cout << "\nEnd of program" << std::endl;
	return 0;
}