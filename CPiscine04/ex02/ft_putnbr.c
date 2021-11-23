/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:42:56 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/01 09:43:12 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	compruebo(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	desgloso(int nb, int aux)
{
	int	pot;
	int	cont;
	int	a;

	cont = 0;
	pot = 1;
	while (aux % 10 != aux)
	{
		pot = pot * 10;
		cont++;
		aux = aux / 10;
	}
	a = 0;
	while (a <= cont)
	{
		ft_putchar(nb / pot + '0');
		nb = nb % pot;
		pot = pot / 10;
		a++;
	}
}

void	ft_putnbr(int nb)
{
	int	aux;

	if (nb == -2147483648)
		compruebo();
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * (-1);
		}
		aux = nb;
		desgloso(nb, aux);
	}
}
