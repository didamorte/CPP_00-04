#include <iostream>
#include <iomanip>

int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	
	std::string* brainPtr = &brain;

	std::string& brainRef = brain;

	std::cout << "Address of brain:		" << &brain << std::endl;
	std::cout << "Address held by brainPtr:	" << brainPtr << std::endl;
	std::cout << "Address held by brainRef:	" << &brainRef << std::endl;

	std::cout << "\nValue of brain:			" << brain << std::endl;
	std::cout << "Value pointed to by brainPtr:	" << *brainPtr << std::endl;
	std::cout << "Value pointed to by brainRef:	" << brainRef << std::endl;

	std::cout << "\nEnd of program" << std::endl;
	return 0;
}