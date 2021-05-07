#include <stdio.h>


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

int	main(void)
{
	char *s = "\0";

	printf("%d", ft_strlen(s));

	return 0;
}
