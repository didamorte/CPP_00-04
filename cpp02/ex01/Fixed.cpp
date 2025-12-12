#include "Fixed.hpp"

Fixed::Fixed(void) : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = n * (1 << this->bits);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = roundf(f * (1 << this->bits));
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
	return (this->num);
}

void	Fixed::set_raw_bits(int const raw)
{
	this->num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->num / (1 << this->bits));
}

int	Fixed::toInt(void) const
{
	return (this->num >> this->bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}