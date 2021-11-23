/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:55:13 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 19:03:20 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		c;
	int		i;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		c++;
	dest = malloc(sizeof(char) * (c + 1));
	if (dest == NULL)
		return (0);
	while (src[i] != '\0')
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{	
		str++;
		i++;
	}
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str;

	i = 0;
	str = malloc(sizeof(t_stock_str) * (ac + 1));
	if (str == NULL)
		return (NULL);
	while (i < ac)
	{
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		str[i].size = ft_strlen(av[i]);
		i++;
	}
	str[i].str = 0;
	str[i].copy = 0;
	str[i].size = 0;
	return (str);
}
