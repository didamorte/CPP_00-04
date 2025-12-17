#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain_;
}

void Dog::makeSound() const {
	std::cout << "Woof! :b" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain_;
}