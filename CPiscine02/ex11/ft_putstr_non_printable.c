/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:15:34 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/04 12:15:03 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] >= 32) && (str[c] <= 126))
			ft_putchar(str[c]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[c] / 16]);
			ft_putchar("0123456789abcdef"[str[c] % 16]);
		}
		c++;
	}
}
