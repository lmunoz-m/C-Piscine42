/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:14:46 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/13 20:43:13 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	printMap(char **str)
{
	int	i;

	i = 1;
	while (str[i][0])
	{
		ft_putstr(str[i]);
		write(1, "\n", 1);
		i++;
	}
}

char	characterIndex(char **table)
{
	int	j;

	j = 0;
	while (table[0][j])
		j++;
	return (table[0][j - 1]);
}

char	obstacleIndex(char **table)
{
	int	j;

	j = 0;
	while (table[0][j])
		j++;
	return (table[0][j - 2]);
}
