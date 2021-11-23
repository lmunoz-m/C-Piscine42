/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:29:35 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/09/26 19:22:53 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	inicio;
	char	fin;

	inicio = 'a';
	fin = 'z';
	while (inicio <= fin)
	{
		write(1, &inicio, 1);
		inicio++;
	}
}
