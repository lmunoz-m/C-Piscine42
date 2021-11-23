/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:19:32 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 13:39:06 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	c_l(char *str, int argc)
{
	int		fd;
	int		n_lines;
	char	c;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		if (argc > 1)
			write(1, "\n", 1);
		return (0);
	}
	n_lines = 0;
	while (read(fd, &c, 1) != 0)
	{
		if (c == '\n')
			n_lines++;
	}
	close(fd);
	return (n_lines);
}

int	checkOpen(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return (-2);
	}
	return (fd);
}

int	c_c(char *str)
{
	char	c;
	int		fd;
	int		count_char[2];
	int		c_l;

	c_l = 0;
	fd = checkOpen(str);
	if (fd == -2)
		return (0);
	while (read(fd, &c, 1) != 0)
	{
		count_char[0] = 1;
		while (c != '\n')
		{
			count_char[0]++;
			read(fd, &c, 1);
		}
		if (c_l++ > 0)
			count_char[0]++;
		if (count_char[0] > count_char[1])
			count_char[1] = count_char[0];
		read(fd, &c, 1);
	}
	close(fd);
	return (count_char[1]);
}

char	**memory_allocation(int lines, int characters)
{
	int		i;
	char	**dicc;

	dicc = (char **) malloc((lines + 1) * sizeof(char *));
	if (dicc == NULL)
		return (0);
	i = 0;
	while (i < lines + 1)
	{
		dicc[i] = (char *) malloc((characters + 1) * sizeof(char));
		if (dicc[i] == NULL)
			return (0);
		i++;
	}
	return (dicc);
}
