#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap clappy("Clappy");
	ClapTrap bob("Bob");

	std::cout << std::endl << "=== Testing attack ===" << std::endl;
	clappy.attack("Enemy");

	std::cout << std::endl << "=== Testing takeDamage ===" << std::endl;
	clappy.takeDamage(3);
	clappy.takeDamage(5);

	std::cout << std::endl << "=== Testing beRepaired ===" << std::endl;
	clappy.beRepaired(4);

	std::cout << std::endl << "=== Testing death ===" << std::endl;
	bob.takeDamage(15);
	bob.attack("Someone");
	bob.beRepaired(5);

	std::cout << std::endl << "=== Testing energy depletion ===" << std::endl;
	ClapTrap energyTest("EnergyTester");
	for (int i = 0; i < 12; i++) {
		energyTest.attack("Target");
	}

	std::cout << std::endl << "=== Testing copy constructor ===" << std::endl;
	ClapTrap clappyCopy(clappy);
	clappyCopy.attack("CopyTarget");

	std::cout << std::endl << "=== Testing assignment operator ===" << std::endl;
	ClapTrap assigned("Assigned");
	assigned = clappy;
	assigned.attack("AssignedTarget");

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}