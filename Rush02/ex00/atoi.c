
#include<stdlib.h>
#include<unistd.h>

void	ft_atoi(char *str)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	y = 1;
	z = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\t')
		i++;
	while ((str[i] > 32 && str[i] < 48) || (str[i] > 57) )
	{
		if (str[i] != '+')
		{
		write(1, "Dict Error", 10);
			write(1, "\n", 1);
		 	exit(1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		str[z] = str[i];
		i++;
		z++;
	}
	str[z] = '\0';
}