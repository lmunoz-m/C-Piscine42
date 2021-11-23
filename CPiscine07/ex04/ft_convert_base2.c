/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:41 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:43 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != 0)
	{
		n++;
	}
	return (n);
}

char	*ft_write_number2(long int pot, long int nbr, char *res, char *base)
{
	int			i;
	long int	aux;
	int			len;

	i = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		res[0] = '-';
		i++;
	}
	aux = nbr;
	while (pot != 1)
	{
		pot = pot / len;
		res[i] = *(base + (aux / pot));
		aux = aux % pot;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_write_number(long int pot, long int nbr, int len, char *base)
{
	int			i;
	long int	aux;
	int			size;
	char		*res;

	aux = nbr;
	size = 0;
	while (aux % pot != aux)
	{
		aux = aux / pot;
		size++;
	}
	res = malloc(sizeof(char) * (size + 2));
	i = 0;
	while (i < size)
	{
		pot = pot * len;
		i++;
	}
	res = ft_write_number2(pot, nbr, res, base);
	return (res);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long int	longnbr;
	int			len;
	long int	pot;
	char		*a;

	longnbr = nbr;
	if (-2147483648 <= longnbr && longnbr <= 2147483647)
	{
		len = ft_strlen(base);
		pot = len;
		a = ft_write_number(pot, longnbr, len, base);
		return (a);
	}
	return (0);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' \
			|| base[i] == '\f' || base[i] == '\n' \
			|| base[i] == '\r' || base[i] == '\t' || base[i] == '\v')
			return (1);
		j = 0;
		while (base[j] != 0)
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}
