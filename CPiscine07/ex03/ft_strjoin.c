/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:54:13 by jlopez-f          #+#    #+#             */
/*   Updated: 2021/10/11 21:27:41 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{	
		str++;
		i++;
	}
	return (i);
}

int	ft_strjoin2(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j] != '\0')
		{
			dest[k] = strs[i][j], j++, k++;
		}
		j = 0;
		if (i != size - 1)
		{	
			while (sep[j] != '\0')
			{
				dest[k] = sep[j], j++;
				k++;
			}
		}
		j = 0, i++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		lent;
	char	*dest;

	i = 0;
	lent = 0;
	if (size <= 0)
	{
		dest = malloc(sizeof(char));
		return (dest);
	}
	while (i < size)
	{
		lent += ft_strlen(strs[i]);
		i++;
	}
	lent += ft_strlen(sep) * (size - 1);
	dest = malloc(sizeof(char) * (lent + 1));
	if (dest == NULL)
		return (0);
	i = ft_strjoin2(size, strs, sep, dest);
	dest[i] = '\0';
	return (dest);
}
