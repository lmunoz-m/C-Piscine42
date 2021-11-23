/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:15:41 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 08:42:31 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_struct(t_s *init, char **str)
{
	init->i = 0;
	init->j = 0;
	init->length = 1;
	init->obstaclenum = 0;
	init->nl = numRows(str);
	init->nc = numCol(str);
	init->portion_to_check = NULL;
	init->coordyfin = 0;
	init->coordxfin = 0;
}

void	else_struct(t_s s, t_s *ptr)
{
	ptr->coordxfin = s.j;
	ptr->coordyfin = s.i;
	ptr->length++;
}

void	bsq(char **str)
{
	t_s	s;

	set_struct(&s, str);
	while (str[s.i][0])
	{
		s.j = 0;
		while (str[s.i][0] != 0)
		{
			if (s.i + s.length - 1 < s.nl && s.j + s.length - 1 < s.nc)
			{
				s.portion_to_check = extract_portion(str, s.length, s.j, s.i);
				s.obstaclenum = obstacle(s.portion_to_check, str, s.length);
				free_mem2(s.length, s.portion_to_check);
				if (s.obstaclenum == 1)
					s.j++;
				else
					else_struct(s, &s);
			}
			else
				break ;
		}
		s.i++;
	}
	put_sqr(str, s.length - 1, s.coordxfin, s.coordyfin);
}
