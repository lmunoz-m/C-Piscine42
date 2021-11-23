/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:26:31 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 13:42:50 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	create_file(void)
{
	int		fd;
	char	c;

	fd = open("input_map", O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
	while (read(0, &c, 1))
	{	
		write(fd, &c, 1);
		if (c == '\n')
			break ;
	}
	close(fd);
}

int	save_first_line(void)
{
	int		i;
	char	*number;
	int		int_number;
	char	**line;
	int		length;

	number = NULL;
	line = NULL;
	line = arr_asg("input_map", c_l("input_map", 0), c_c("input_map"));
	length = ft_strlen(line[0]);
	i = 0;
	number = malloc((length) * sizeof(char));
	while (i < length - 3)
	{
		number[i] = line[0][i];
		i++;
	}
	int_number = ft_atoi(number);
	free(number);
	free_mem3(line);
	return (int_number);
}

void	create_map(void)
{
	int		fd;
	int		i;
	char	c;
	int		int_number;

	create_file();
	int_number = save_first_line();
	i = 0;
	fd = open("input_map", O_APPEND | O_WRONLY);
	while (i < int_number)
	{
		while (read(0, &c, 1))
		{
			write(fd, &c, 1);
			if (c == '\n')
				break ;
		}
		i++;
	}
	close(fd);
}
