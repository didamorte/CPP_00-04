#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========== BASIC TEST =========" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "========== ARRAY OF ANIMALS =========" << std::endl;
	const int size = 4;
	Animal* animals[size];

	std::cout << std::endl << "--- Creating Dogs ---" << std::endl;
	for (int k = 0; k < size / 2; k++) {
		animals[k] = new Dog();
		std::cout << std::endl;
	}

	std::cout << "--- Creating Cats ---" << std::endl;
	for (int k = size / 2; k < size; k++) {
		animals[k] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "--- Making sounds ---" << std::endl;
	for (int k = 0; k < size; k++) {
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	std::cout << std::endl << "--- Deleting Animals ---" << std::endl;
	for (int k = 0; k < size; k++) {
		delete animals[k];
		std::cout << std::endl;
	}

	std::cout << "========== DEEP COPY TEST =========" << std::endl;
	std::cout << std::endl << "--- Creating original Dog ---" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I want to play!");
	originalDog->getBrain()->setIdea(1, "I want food!");

	std::cout << std::endl << "--- Creating copy Dog ---" << std::endl;
	Dog* copyDog = new Dog(*originalDog);

	std::cout << std::endl << "--- Checking ideas ---" << std::endl;
	std::cout << "Original Dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "--- Modifying copy's brain ---" << std::endl;
	copyDog->getBrain()->setIdea(0, "I'm a different dog!");

	std::cout << "Original Dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy Dog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "--- Verifying deep copy (addresses should be different) ---" << std::endl;
	std::cout << "Original Brain address: " << originalDog->getBrain() << std::endl;
	std::cout << "Copy Brain address: " << copyDog->getBrain() << std::endl;

	std::cout << std::endl << "--- Deleting dogs ---" << std::endl;
	delete originalDog;
	delete copyDog;

	std::cout << std::endl << "========== ASSIGNMENT OPERATOR TEST =========" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "Original idea");
	
	std::cout << std::endl << "--- Assigning dog1 to dog2 ---" << std::endl;
	Dog dog2;
	dog2 = dog1;

	std::cout << std::endl << "--- Modifying dog2's brain ---" << std::endl;
	dog2.getBrain()->setIdea(0, "Modified idea");

	std::cout << "Dog1 idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "--- End of scope, destructors called ---" << std::endl;
	return 0;
}