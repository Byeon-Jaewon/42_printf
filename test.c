#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	num = 10;
	int *c = &num;

	printf("%0*.*i",2,-2,8);

	return 0;
}
