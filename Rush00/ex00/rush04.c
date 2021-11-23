/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:51:49 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/09/25 13:53:18 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top_botton(int contadorx, int x)
{
	while (contadorx <= x)
	{
		if (contadorx == 1)
			ft_putchar('A');
		else if (contadorx != x)
			ft_putchar('B');
		else if (contadorx == x)
			ft_putchar('C');
		contadorx++;
	}
}

void	middle(int contadorxy, int x)
{
	while (contadorxy <= x)
	{
		if (contadorxy == 1)
			ft_putchar('B');
		else if (contadorxy != x)
			ft_putchar(' ');
		else if (contadorxy == x)
			ft_putchar('B');
		contadorxy++;
	}
}

void	rush(int x, int y)
{
	int		contadorx;
	int		contadory;

	contadorx = 1;
	contadory = 1;
	top_botton(contadorx, x);
	if (x != 0 && y != 0)
		ft_putchar('\n');
	while (contadory < y - 1)
	{
		contadorx = 1;
		middle(contadorx, x);
		ft_putchar('\n');
		contadory++;
	}
	contadorx = 1;
	if (contadorx < y - 1)
	{
        while (contadorx <= x)
        {
            if (contadorx == 1)
                ft_putchar('C');
            else if (contadorx != x)
                ft_putchar('B');
            else if (contadorx == x)
                ft_putchar('A');
            contadorx++;
        }
		ft_putchar('\n');
	}
}


