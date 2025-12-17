#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type_(type) {
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other) {
		type_ = other.type_;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type_;
}