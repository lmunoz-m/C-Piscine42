/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:42:12 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/06 17:43:01 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_error(char *base, int lenb)
{
	int	i;
	int	j;

	i = 0;
	if (lenb == 0 || lenb == 1)
		return (1);
	while (i < lenb)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' \
		|| base[i] == '\r' || base[i] == '\t' || base[i] == '\v')
			return (1);
		j = i + 1;
		while (j < lenb)
		{
			if (base[i] != base[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ftcheckb(char *base, char car)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (car == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long int	ft_atoi_base2(char *str, char *base, int i, long int s)
{
	int			index;
	int			lenb;
	long int	r;

	r = 0;
	lenb = ft_strlen(base);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		index = ftcheckb(base, str[i]);
		if (index == -1)
			return (s * r);
		r = r * lenb + (index);
		i++;
	}
	return (s * r);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	long int	s;
	int			lenb;
	int			err;
	long int	nb;

	i = 0;
	s = 1;
	lenb = ft_strlen(base);
	err = ft_error(base, lenb);
	if (err == 1)
		return (0);
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	nb = ft_atoi_base2(str, base, i, s);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return ((int) nb);
}
