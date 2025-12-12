#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					num;
		static const int	bits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &rhs);
		~Fixed(void);
		int		get_raw_bits(void) const;
		void	set_raw_bits(int const raw);
};

#endif