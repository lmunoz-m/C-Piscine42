/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:46:42 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 09:41:18 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_mem(int lines, char **dicc)
{
	int	i;

	i = 0;
	while (i < lines)
		free(dicc[i++]);
	free(dicc);
}

void	free_mem2(int lines, char **dicc)
{
	int	i;

	i = 0;
	while (i <= lines)
		free(dicc[i++]);
	free(dicc);
}

void	free_mem3(char **line)
{
	free(line[0]);
	free(line[1]);
	free(line);
}
