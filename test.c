#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == "\0")
		return (1);
	while (str[i] != '\0')
		i++;
	return (i);
}
int		ft_putstr(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (s == 0)
		return (0);
	write(1, s, len);
	return (len);
}
int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(int n)
{
	int		ret;

	ret = 0;
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
		return (11);
	}
	else
	{
		if (n < 0)
		{
			ret += ft_putchar('-');
			n = n * (-1);
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ret += ft_putchar((n % 10) + '0');
	}
	return (ret);
}



int	main(void)
{
	char *s = "\0";

	ft_putnbr(2147483650);

	return 0;
}
