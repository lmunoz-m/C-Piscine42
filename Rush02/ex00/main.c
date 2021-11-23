/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:02:03 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/10 21:09:33 by lmunoz-m         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	char **dicc;
	int i;

	if (argc == 1)
	{
		write(1, "Dict Error", 10);
		write(1, "\n", 1);
		exit(1);
	}
	else if (argc == 2)
	{
		dicc = add();
		ft_atoi(argv[1]);
		start(argv[1], dicc);
		return (0);
	}
	else if (argc == 3)
	{
		dicc = add1(argv[1]);
		ft_atoi(argv[2]);
		start(argv[2], dicc);
		return (0);
	}
	else
	{
		write(1, "Dict Error", 10);
		write(1, "\n", 1);
		exit(1);
	}
}