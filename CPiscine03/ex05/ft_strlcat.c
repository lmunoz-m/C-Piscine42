/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:12:55 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/04 10:41:21 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
	unsigned int	t;

	x = 0;
	z = ft_strlen(src);
	y = ft_strlen(dest);
	if (size < y + 1)
	{
		dest[y] = '\0';
		return (z + size);
	}
	else
	{
		t = size - y - 1;
		while (x < t && *(src + x) != 0)
		{
			*(dest + y + x) = *(src + x);
			x++;
		}
		*(dest + y + x) = '\0';
		return (z + y);
	}
}
