#include <stdio.h>
#include <unistd.h>
int		decimal_digit(int d)
{
	int		ret;

	if (d == 0)
		ret = 1;
	else
		ret = 0;
	while (d != 0)
	{
		d /= 10;
		ret++;
	}
	return (ret);
}
int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int		ft_putui(unsigned int n)
{
	int		ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putui(n / 10);
	}
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}
int	main(void)
{
	char *s = "\0";

	ft_putui(4294967297);

	return 0;
}
