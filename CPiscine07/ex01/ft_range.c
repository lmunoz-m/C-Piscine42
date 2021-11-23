/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:15:08 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 15:15:10 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int			*dest;
	long int	diff;
	long int	i;

	diff = (long int)max - (long int)min;
	i = -1;
	if (diff <= 0)
		return (0);
	dest = malloc((sizeof(int) * diff));
	if (dest == NULL)
		return (0);
	while (++i < diff)
		dest[i] = (long int)min + i;
	return (dest);
}
