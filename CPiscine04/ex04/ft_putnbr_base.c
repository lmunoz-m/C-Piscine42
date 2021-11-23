/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:49:17 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/05 21:06:02 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int	ft_error(char *base, int lenb)
{
	int	i;
	int	j;

	i = 0;
	if (lenb == 0 || lenb == 1)
		return (1);
	while (i < lenb)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (j < lenb)
		{
			if (base[i] != base[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putnbr(long int nb, int lenb, char *base)
{
	if (nb < 0)
	{
		ft_putchar ('-');
		ft_putnbr (-nb, lenb, base);
	}
	else if (nb > lenb - 1)
	{
		ft_putnbr (nb / lenb, lenb, base);
		ft_putnbr (nb % lenb, lenb, base);
	}
	else
		ft_putchar (base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			lenb;
	int			err;
	long int	nb;

	lenb = ft_strlen (base);
	err = ft_error (base, lenb);
	nb = nbr;
	if (err == 1)
		return ;
	ft_putnbr (nb, lenb, base);
}
