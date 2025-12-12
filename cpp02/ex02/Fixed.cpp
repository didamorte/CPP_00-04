#include "Fixed.hpp"

Fixed::Fixed(void) : num(0)
{
}

Fixed::Fixed(int const n)
{
	this->num = n * (1 << this->bits);
}

Fixed::Fixed(float const f)
{
	this->num = roundf(f * (1 << this->bits));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->num = rhs.get_raw_bits();
	return (*this);
}

Fixed::~Fixed(void)
{
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

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->num > rhs.num);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->num < rhs.num);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->num >= rhs.num);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->num <= rhs.num);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->num == rhs.num);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->num != rhs.num);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result;

	result.set_raw_bits(this->num + rhs.num);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result;

	result.set_raw_bits(this->num - rhs.num);
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result;

	result.set_raw_bits((this->num * rhs.num) >> this->bits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result;

	result.set_raw_bits((this->num << this->bits) / rhs.num);
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->num++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->num++;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->num--;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}