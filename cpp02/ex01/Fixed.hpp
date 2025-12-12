#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					num;
		static const int	bits = 8;

	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &rhs);
		~Fixed(void);
		int		get_raw_bits(void) const;
		void	set_raw_bits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif