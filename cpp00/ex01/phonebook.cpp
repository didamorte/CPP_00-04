#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(){}

Contact::~Contact(){}

void Contact::setContact(std::string first, std::string last, 
						std::string nick, std::string phone, std::string secret)
{
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

// Implementação dos métodos
PhoneBook::PhoneBook()
{
	contactCount = 0;
	oldestIndex = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;
	int index;

	std::cout << "First Name: ";
	std::cin >> first;
	std::cout << "Last Name: ";
	std::cin >> last;
	std::cout << "Nickname: ";
	std::cin >> nick;
	std::cout << "Phone Number: ";
	std::cin >> phone;
	std::cout << "Darkest Secret: ";
	std::cin >> secret;
	
	if (contactCount < 8)
	{
		index = contactCount;
		contactCount++;
	}
	else
	{
		index = oldestIndex;
		oldestIndex = (oldestIndex + 1) % 8;
	}

	contacts[index].setContact(first, last, nick, phone, secret);
	std::cout << "Contact added!" << std::endl;
}

std::string formatField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::showContact()
{
	if (contactCount == 0)
	{
		std::cout << "No contacts!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < contactCount && i < 8; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << formatField(contacts[i].getNickname()) << std::endl;
	}

	int index;
	std::cout << "Enter index to display: ";
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= contactCount)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Input Comand (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (!(std::cin >> command))
			break;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.showContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid Input!" << std::endl;
	}

	return 0;
}