#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>


int		decimal_digit(int d)
{
	int		ret;

	if (d == 0)
		return (1);
	ret = 0;
	while (d != 0)
	{
		d /= 10;
		ret++;
	}
	return (ret);
}

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

void		ft_putnbr_hex(long d)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (d < 0)
	{
		d *= -1;
		ft_putchar('-');
		ft_putnbr_hex(d);
	}
	else if (d < 16)
		ft_putchar(hex[d]);
	else
	{
		ft_putnbr_hex(d / 16);
		ft_putchar(hex[d % 16]);
	}
}

int		main(void)
{
	int		i = -10000;
	int		a;

	ft_putchar(38);

	return 0;
}
