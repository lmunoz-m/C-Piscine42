/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 08:20:40 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/06 19:31:20 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_print_params(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argc > 1)
	{
		ft_putstr(argv[i]);
		write (1, "\n", 1);
		i++;
		argc--;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*aux;

	i = 1;
	while (argc - 1 > i)
	{
		if (ft_strcmp (argv[i], argv[i + 1]) > 0)
		{
			aux = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = aux;
			i = 1;
		}
		else
			i++;
	}
	ft_print_params (argc, argv);
	return (0);
}
