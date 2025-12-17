#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), brain_(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain_(new Brain(*other.brain_)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain_;
		brain_ = new Brain(*other.brain_);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain_;
}

void Cat::makeSound() const {
	std::cout << "Meow! :3" << std::endl;
}

Brain* Cat::getBrain() const {
	return brain_;
}