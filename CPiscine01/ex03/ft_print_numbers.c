/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:11:08 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/09/30 13:09:09 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	ft_print_numbers(void)
{
	char	inicio;
	char	fin;

	inicio = '0';
	fin = '9';
	while (inicio <= fin)
	{
		write(1, &inicio, 1);
		inicio++;
	}
}
