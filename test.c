#include <stdio.h>

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

int		main(void)
{
	int		i = 100;
	int		a;

	printf("%d",printf("asdf%d", i));

	return 0;
}
