/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:17:36 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/14 15:17:37 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str);
void	ft_write_number(long int pot, long int nbr, int len, char *base);
char	*ft_putnbr_base(int nbr, char *base);
int		ft_check(char *base);

int	*ft_count(char *str)
{
	static int	vec[2];
	int			i;

	vec[0] = 0;
	i = 0;
	while (*(str + vec[0]) == ' ' || *(str + vec[0]) == '\t' \
	|| *(str + vec[0]) == '\n' || *(str + vec[0]) == '\v' \
	|| *(str + vec[0]) == '\f' || *(str + vec[0]) == '\r')
		vec[0]++;
	while (*(str + vec[0]) == '+' || *(str + vec[0]) == '-')
	{
		if (*(str + vec[0]) == '-')
			i++;
		vec[0]++;
	}
	if (i % 2 == 0)
		vec[1] = 1;
	else if (i % 2 == 1)
		vec[1] = -1;
	return (vec);
}

int	ft_is_in_base(int i, char *str, char *base)
{
	int	check;
	int	l;
	int	j;

	check = 1;
	j = i;
	while (j <= ft_strlen(str) && check == 1)
	{
		l = 0;
		check = 0;
		while (l < ft_strlen(base))
		{
			if (str[j] == base[l])
			{
				check++;
				l = ft_strlen(base);
			}
			l++;
		}
		j++;
	}
	return (j - i - 1);
}

int	ft_find(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int			len;
	int			i;
	long int	pot;
	long int	nb;

	if (ft_check(base) == 0)
	{
		pot = 1;
		i = 0;
		nb = 0;
		len = ft_is_in_base(ft_count(str)[0], str, base);
		while (i < len)
		{
			nb = (nb * ft_strlen(base)) + \
			ft_find(str[i + ft_count(str)[0]], base);
			i++;
		}	
		nb *= ft_count(str)[1];
		if (nb < 2147483648 && nb >= -2147483648)
			return (nb);
		return (0);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		a;
	char	*res;

	if (ft_check(base_from) == 1 || ft_check(base_to) == 1)
		return (0);
	a = ft_atoi_base(nbr, base_from);
	res = ft_putnbr_base(a, base_to);
	return (res);
}
