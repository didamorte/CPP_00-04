#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "========== CLAPTRAP TESTS ==========" << std::endl;
	std::cout << std::endl << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clappy("Clappy");

	std::cout << std::endl << "=== ClapTrap actions ===" << std::endl;
	clappy.attack("Enemy");
	clappy.takeDamage(3);
	clappy.beRepaired(2);

	std::cout << std::endl << "========== SCAVTRAP TESTS ==========" << std::endl;
	std::cout << std::endl << "=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << std::endl << "=== ScavTrap attack (20 damage) ===" << std::endl;
	scav.attack("Target");

	std::cout << std::endl << "=== ScavTrap takeDamage ===" << std::endl;
	scav.takeDamage(30);

	std::cout << std::endl << "=== ScavTrap beRepaired ===" << std::endl;
	scav.beRepaired(20);

	std::cout << std::endl << "=== ScavTrap guardGate ===" << std::endl;
	scav.guardGate();

	std::cout << std::endl << "=== ScavTrap death test ===" << std::endl;
	ScavTrap scavDeath("DeathTest");
	scavDeath.takeDamage(100);
	scavDeath.attack("Nobody");
	scavDeath.guardGate();

	std::cout << std::endl << "=== ScavTrap energy test ===" << std::endl;
	ScavTrap energyScav("EnergyScav");
	for (int i = 0; i < 52; i++) {
		energyScav.attack("Target");
	}

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}