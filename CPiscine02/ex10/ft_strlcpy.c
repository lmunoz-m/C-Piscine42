/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:35:43 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/04 12:23:45 by lmunoz-m         ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	k;
	unsigned int	h;

	k = 0;
	h = ft_strlen(src);
	if (size != 0)
	{
		while ((src[k] != '\0') && (k < size - 1))
		{
			dest[k] = src[k];
			k++;
		}
		dest[k] = '\0';
	}
	return (h);
}
