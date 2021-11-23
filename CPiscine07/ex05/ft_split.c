/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:22 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:24 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != 0)
		n++;
	return (n);
}

int	ft_find(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j] != '\0')
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	j;
	int	cpal;

	j = 0;
	cpal = 0;
	while (ft_find(str[j], charset) == 1)
		j++;
	while (str[j] != '\0')
	{
		while (ft_find(str[j], charset) == 0 && str[j] != '\0')
			j++;
		cpal++;
		while (ft_find(str[j], charset) && str[j] != '\0')
			j++;
	}
	return (cpal);
}

int	ft_split2(char *str, char *charset, int i, char **result)
{
	int	j;
	int	k;
	int	cpal;

	cpal = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (ft_find(str[j], charset) == 0 && str[j] != '\0')
			j++;
		result[cpal] = malloc((j - i + 1) * sizeof(char));
		j = i;
		k = 0;
		while (ft_find(str[j], charset) == 0 && str[j] != '\0')
			result[cpal][k] = str[j], j++, k++;
		result[cpal][k] = '\0';
		while (ft_find(str[j], charset) == 1 && str[j] != '\0')
			j++;
		cpal++;
		i = j;
	}
	return (cpal);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cpal;
	char	**result;

	i = 0;
	result = malloc((ft_count(str, charset) + 1) * sizeof(char *));
	while (ft_find(str[i], charset) == 1)
		i++;
	cpal = ft_split2(str, charset, i, result);
	result[cpal] = NULL;
	return (result);
}
