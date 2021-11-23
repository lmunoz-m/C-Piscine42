/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:39:21 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 09:40:48 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	it_numCol(char **table, int i)
{
	int	j;

	j = 0;
	while (table[i][j])
		j++;
	return (j);
}

int	m_cr_aux(char **map, int row_length, int int_number)
{
	int	i;

	i = 1;
	while (map[i][0] != 0)
	{
		if (row_length != int_number)
			return (1);
		if (i + 1 <= int_number)
		{
			if (it_numCol(map, i) != it_numCol(map, i + 1))
				return (1);
		}
		i++;
	}
	return (0);
}

int	m_cr(char **map)
{
	int		i;
	int		length;
	int		int_number;
	int		count;
	char	*number;

	count = 0;
	length = ft_strlen(map[0]);
	i = 0;
	number = malloc((length) * sizeof(char));
	while (i < length - 3)
	{
		number[i] = map[0][i];
		i++;
	}
	int_number = ft_atoi(number);
	free(number);
	if (m_cr_aux(map, numRows(map), int_number) == 1)
		return (1);
	return (0);
}

int	m_f(char **map)
{
	int	num_col;

	num_col = it_numCol(map, 0);
	if (num_col < 4)
		return (1);
	if (map[0][num_col - 1] == map[0][num_col - 2])
		return (1);
	else if (map[0][num_col - 1] == map[0][num_col - 3])
		return (1);
	else if (map[0][num_col - 2] == map[0][num_col - 3])
		return (1);
	return (0);
}

int	m_c(char **map)
{
	int		i;
	int		num_col;
	int		j;
	char	base;
	char	obs;

	num_col = it_numCol(map, 0);
	base = map[0][num_col - 3];
	obs = map[0][num_col - 2];
	i = 1;
	while (map[i][0])
	{
		j = 0;
		if (map[i][0] == 0)
			return (1);
		while (map[i][j] != 0)
		{
			if (map[i][j] != base && map[i][j] != obs)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}
