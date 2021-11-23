/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:10:45 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/13 18:23:09 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	caracter;

	caracter = 0;
	while (str[caracter] != '\0')
	{
		caracter++;
	}
	return (caracter);
}

int	numRows(char **table)
{
	int	i;

	i = 0;
	while (table[i][0])
	{
		i++;
	}
	i--;
	return (i);
}

int	numCol(char **table)
{
	int	j;

	j = 0;
	while (table[1][j])
	{
		j++;
	}
	return (j);
}

int	ft_atoi(char *str)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	y = 1;
	z = 0;
	while ((str[i] <= 9 && str[i] >= 13) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			y *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = (str[i] - '0') + (z * 10);
		i++;
	}
	return (z * y);
}
