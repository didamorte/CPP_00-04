#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();
		void setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int contactCount;
		int oldestIndex;

	public:
		PhoneBook();  // declaração do construtor
		~PhoneBook(); // declaração do destrutor
		void addContact();
		void showContact();
};

#endif