/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:13:05 by jlallana          #+#    #+#             */
/*   Updated: 2021/10/11 17:03:18 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void ft_atoi(char *str);
void start(char *str, char **dicc);
int unidades(char c, char **dicc, int i);
int decenas(char c, char **dicc, int i, char c2);
int centenas(char c, char **dicc, int i);
char **add1(char *str);
char **add();
void zero_unidad(char c, char **dicc, int i);
int cifras(int tam, int i, char **dicc);
void ft_long(int j);

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void start(char *str, char **dicc)
{
	int i;
	int j;
	int k;
	int cont;
	int tam;
	int contc = 0;
	i = 0;
	j = 0;
	k = 0;
	cont = 0;
	tam = (ft_strlen(str));
	while (dicc[i][0] != 0)
	{
		if (tam == 1 && str[k] == '0')
			zero_unidad(str[k], dicc, i);

		if (tam > 1 && str[k] == '0')
			k++;

		else if (tam > 3)
		{
			ft_long(tam - k - 1);
			write(1, "\n", 1);
			tam = 0;
		}

		if ((tam - k - 1) % 3 == 2)
		{
			if (str[k] != '1')
			{
				if (unidades(str[k], dicc, i) == 1)
				{
					j = 0;
					write(1, " ", 1);
				}
				if (centenas('1', dicc, i) == 1)
				{
					k++;
					j = 0;
					i = 0;
					write(1, " ", 1);
				}
				else
				{
					i++;
				}
			}
			else if (centenas(str[k], dicc, i) == 1)
			{
				k++;
				j = 0;
				i = 0;
				write(1, " ", 1);
			}
			else
			{
				i++;
			}
		}
		else if ((tam - k - 1) % 3 == 1)
		{
			if (decenas(str[k], dicc, i, str[k + 1]) == 1)
			{
				if (str[k + 1] != '0')
					write(1, " ", 1);
				else
					write(1, "\n", 1);
				k++;
				j = 0;
				i = 0;
			}
			else
			{
				i++;
			}
		}
		else if (((tam - k - 1) % 3 == 0))
		{

			if (unidades(str[k], dicc, i) == 1)
			{
				k++;
				j = 0;
				write(1, "\n", 1);
			}
			else
			{
				i++;
			}
		}

		else
		{
			i++;
		}
	}
}

int unidades(char c, char **dicc, int i)
{
	int cont = 0;
	int j = 0;
	cont = 0;
	if (dicc[i][j] == c && c != '0')
	{
		if ((dicc[i][j + 1] == ' ' || dicc[i][j + 1] == ':'))
		{
			j = 1;
			while (dicc[i][j] == ' ' || dicc[i][j] == ':')
				j++;
			while (dicc[i][j] != '\n')
			{
				write(1, &dicc[i][j], 1);
				j++;
			}
			cont = 1;
		}
	}
	return cont;
}

void zero_unidad(char c, char **dicc, int i)
{
	int j = 0;

	if (dicc[i][j] == c)
	{
		if ((dicc[i][j + 1] == ' ' || dicc[i][j + 1] == ':'))
		{
			j = 1;
			while (dicc[i][j] == ' ' || dicc[i][j] == ':')
				j++;
			while (dicc[i][j] != '\n')
			{
				write(1, &dicc[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
		}
	}
}

int decenas(char c, char **dicc, int i, char c2)
{
	int cont;
	int j = 0;
	cont = 0;

	if (dicc[i][j] == c && (c == '1'))
	{
		if (dicc[i][j + 1] == c2)
		{
			if ((dicc[i][j + 2] == ' ' || dicc[i][j + 2] == ':'))
			{
				j = 2;
				while (dicc[i][j] == ' ' || dicc[i][j] == ':')
					j++;
				while (dicc[i][j] != '\n')
				{
					write(1, &dicc[i][j], 1);
					j++;
				}
				cont = 1;
				write(1, "\n", 1);
				exit(1);
			}
		}
	}
	else if (dicc[i][j] == c)
	{
		if (dicc[i][j + 1] == '0')
		{
			if ((dicc[i][j + 2] == ' ' || dicc[i][j + 2] == ':'))
			{
				j = 2;
				while (dicc[i][j] == ' ' || dicc[i][j] == ':')
					j++;
				while (dicc[i][j] != '\n')
				{
					write(1, &dicc[i][j], 1);
					j++;
				}
				cont = 1;
			}
		}
	}
	return cont;
}
int centenas(char c, char **dicc, int i)
{
	int cont;
	int j = 0;
	cont = 0;
	if (dicc[i][j] == '1')
	{
		if (dicc[i][j + 1] == '0')
		{
			if (dicc[i][j + 2] == '0')
			{
				if ((dicc[i][j + 3] == ' ' || dicc[i][j + 3] == ':'))
				{
					j = 3;
					while (dicc[i][j] == ' ' || dicc[i][j] == ':')
						j++;
					while (dicc[i][j] != '\n')
					{
						write(1, &dicc[i][j], 1);
						j++;
					}
					cont = 1;
				}
			}
		}
	}
	return cont;
}

void ft_long(int j)
{
	int i;
	int n;
	char **dicc;
	i = 0;
	dicc = add();
	while (dicc[i][0] != 0)
	{
		if (dicc[i][0] == '1')
		{
			n = 1;
			while (n <= j)
			{
				if (dicc[i][n] == '0' && (dicc[i][j + 1] == ' ' || dicc[i][j + 1] == ':'))
				{
					if (n == j)
					{
						n = j + 1;
						while (dicc[i][n] == ' ' || dicc[i][n] == ':')
							n++;
						while (dicc[i][n] != '\n')
						{
							write(1, &dicc[i][n], 1);
							n++;
						}
					}
				}
				n++;
			}
		}
		i++;
	}
}
