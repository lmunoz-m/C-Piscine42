/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvargas <guvargas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:37:57 by guvargas          #+#    #+#             */
/*   Updated: 2021/10/14 13:38:55 by guvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	func_aux(char **argv, char **file, int i)
{
	write(2, "map error\n", 10);
	free_mem2(c_l(argv[i], 0), file);
}

void	func_aux2(char **argv, char **file, int i, int argc)
{
	bsq(file);
	if (argc > 1)
		write(1, "\n", 1);
	free_mem2(c_l(argv[i], 0), file);
}

void	set_main(t_main *init)
{
	init->i = 1;
	init->fl = 0;
}

int	func_fail(void)
{
	write(2, "map error\n", 10);
	exit(0);
}
