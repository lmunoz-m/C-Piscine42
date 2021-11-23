/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:20:03 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 07:51:08 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
char	**bookmem(char **portion, int length)
{
	int	i;

	portion = (char **) malloc((length + 1) * sizeof(char *));
	i = 0;
	while (i < length + 1)
	{
		portion[i] = (char *) malloc((length + 1) * sizeof(char));
		if (portion[i] == NULL)
			return (0);
		i++;
	}
	return (portion);
}

char	**extract_portion(char **map, int length, int x, int y)
{
	char	**returned_portion;
	int		i;
	int		j;
	int		aux;
	int		auy;

	y += 1;
	aux = x;
	auy = y;
	returned_portion = NULL;
	returned_portion = bookmem(returned_portion, length);
	i = 0;
	while (i < length)
	{	
		j = 0;
		x = aux;
		while (j < length)
			returned_portion[i][j++] = map[y][x++];
		y++;
		i++;
	}
	returned_portion[i][0] = 0;
	return (returned_portion);
}

void	put_sqr(char **map, int length, int x, int y)
{
	int		i;
	int		j;
	int		aux;
	char	fill;

	fill = characterIndex(map);
	y += 1;
	aux = x;
	i = 0;
	while (i++ < length)
	{
		x = aux;
		j = 0;
		while (j++ < length)
			map[y][x++] = fill;
		y++;
	}
	printMap(map);
}

int	obstacle(char **sqr, char **map, int length)
{
	int		i;
	int		j;
	char	obstacle_char;

	obstacle_char = obstacleIndex(map);
	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (sqr[i][j] == obstacle_char)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
