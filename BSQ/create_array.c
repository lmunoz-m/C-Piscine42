/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:58:35 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 09:39:34 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_struct_2(t_mi_struct_2 *init, char *str, int lines, int characters)
{
	init->i = -1;
	init->j = 0;
	init->fd = checkOpen(str);
	init->dicc = memory_allocation(lines, characters);
}

void	if_struct(t_mi_struct_2 ptr_struct_2, t_mi_struct_2 *ptr)
{
	if (ptr_struct_2.c != '\n')
	{
		ptr->dicc[ptr->i][ptr->j++] = ptr_struct_2.c;
		read(ptr->fd, &ptr->c, 1);
		if (ptr->c == '\n')
			ptr->dicc[ptr->i][ptr->j] = ptr_struct_2.c;
	}
	else
		ptr->dicc[ptr->i][ptr->j++] = '\0';
}

char	**arr_asg(char *str, int lines, int characters)
{
	t_mi_struct_2	ptr_struct_2;

	set_struct_2(&ptr_struct_2, str, lines, characters);
	if (ptr_struct_2.fd == -2)
		return (0);
	while (read(ptr_struct_2.fd, &ptr_struct_2.c, 1) != 0)
	{
		while (++ptr_struct_2.i < lines)
		{
			ptr_struct_2.j = 0;
			while (ptr_struct_2.j < characters + 1)
				if_struct(ptr_struct_2, &ptr_struct_2);
			read(ptr_struct_2.fd, &ptr_struct_2.c, 1);
		}
	}
	close(ptr_struct_2.fd);
	ptr_struct_2.dicc[ptr_struct_2.i][0] = 0;
	return (ptr_struct_2.dicc);
}
