#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name_("default"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << "ClapTrap " << name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name_(other.name_), hitPoints_(other.hitPoints_),
	  energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_) {
	std::cout << "ClapTrap " << name_ << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name_ << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (energyPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ClapTrap " << name_ << " attacks " << target
		<< ", causing " << attackDamage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
		return;
	}
	if (amount >= hitPoints_) {
		hitPoints_ = 0;
		std::cout << "ClapTrap " << name_ << " takes " << amount
			<< " points of damage and dies!" << std::endl;
	} else {
		hitPoints_ -= amount;
		std::cout << "ClapTrap " << name_ << " takes " << amount
			<< " points of damage! (" << hitPoints_ << " HP left)" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no hit points left and cannot repair!" << std::endl;
		return;
	}
	if (energyPoints_ == 0) {
		std::cout << "ClapTrap " << name_ << " has no energy points left and cannot repair!" << std::endl;
		return;
	}
	energyPoints_--;
	hitPoints_ += amount;
	std::cout << "ClapTrap " << name_ << " repairs itself, regaining " << amount
		<< " hit points! (" << hitPoints_ << " HP now)" << std::endl;
}