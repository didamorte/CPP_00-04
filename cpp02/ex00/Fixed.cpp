#include "Fixed.hpp"

Fixed::Fixed(void) : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->num = rhs.get_raw_bits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::get_raw_bits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void	Fixed::set_raw_bits(int const raw)
{
	this->num = raw;
}