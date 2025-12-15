#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << std::endl << "========== FRAGTRAP TESTS ==========" << std::endl;
	std::cout << std::endl << "=== Creating FragTrap ===" << std::endl;
	FragTrap frag("Fraggy");

	std::cout << std::endl << "=== FragTrap attack (30 damage) ===" << std::endl;
	frag.attack("Target");

	std::cout << std::endl << "=== FragTrap takeDamage ===" << std::endl;
	frag.takeDamage(50);

	std::cout << std::endl << "=== FragTrap beRepaired ===" << std::endl;
	frag.beRepaired(25);

	std::cout << std::endl << "=== FragTrap highFivesGuys ===" << std::endl;
	frag.highFivesGuys();

	std::cout << std::endl << "=== FragTrap death test ===" << std::endl;
	FragTrap fragDeath("FragDeath");
	fragDeath.takeDamage(100);
	fragDeath.attack("Nobody");
	fragDeath.highFivesGuys();

	std::cout << std::endl << "=== FragTrap energy test ===" << std::endl;
	FragTrap energyFrag("EnergyFrag");
	for (int i = 0; i < 102; i++) {
		energyFrag.attack("Target");
	}

	std::cout << std::endl << "=== Destructors ===" << std::endl;
	return 0;
}