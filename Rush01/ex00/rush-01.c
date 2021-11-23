/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmunoz-m <lmunoz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 07:51:17 by lmunoz-m          #+#    #+#             */
/*   Updated: 2021/10/02 17:22:28 by lmunoz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void rush01 (char *str);
int check(char *str);

int main  (int argc, char *argv[])
{
	/*if (argc != 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	} */
	int result = 0;
	result = check ("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	if (result == 1)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	rush01("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	return (0);
}

int check(char *str)
{
	int i = 0;
	int cont = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '4'){ //comprobamos que no hay mas de 2 cuatros
			cont++;
			if(cont > 2){
				printf("demasiads 4");
				return 1;
			}
		}
		if ((str[i] < '1' || str[i] > '4') && i % 2 == 0) //comprobamos que los numeros van del 1-5
		{
			printf("%c",str[i] );
			return 1;
		}
		i++;
	}
	if (i != 31){ //31 por la ultima iteracion
	printf("demasiados char");
		return 1;
	}
	return 0;
}


void rush01(char *str)
{
	
	int i = 0;
	int j = 0;
	char colup[4];
	char coldown[4];
	char rowleft[4];
	char rowright[4];
//	char coordenadas[4][4];

/* 	char **coordenadas; //coordenadas[y][x]
	coordenadas = malloc(4 * 1);
	

	if(coordenadas == NULL)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
	}
	for(i = 0; i < x; i++)
	{
		coordenadas[i] = malloc(4 * 1);
		if(coordenadas[i] == NULL)
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
		}
	} */

	while (str[i] != '\0')
	{
		if(i % 2 == 0)
		{
			
			if (i<=6)
			{
				colup[j] = str[i];
			}
			else if (i >= 8 && i<=14)
			{
				if(i==8)
					j = 0;
			
				coldown[j] = str[i];
			}
			else if (i>=16 && i<=22)
			{
				if(i==16)
					j = 0; 

				rowleft[j] = str[i];
			}
			else if (i>=24 && i<=30)
			{
				if(i==24)
					j = 0; 
				rowright[j] = str[i];
			}
			j++;
		}
		i += 2;

	}
	

	i = 0;
	char coordenadas[4][4];
	int x = 0;
	int y = 0;
	
	while(x<=3 && y<=3)
	{
		while(i<=3)
		{
			if(rowleft[i] == '4' && rowright[i] == '1' )
			{
				coordenadas[0][x] = '1';
			}
			else
			{
				coordenadas[0][x] = '0';
			}
		x++;	
		i++;
		}
		x = 0;
		i = 0;
		while(i<=3)
		{
			if(coldown[i] == '4')
			{
				coordenadas[3][x] = '1';
			}
			else
			{
				coordenadas[3][x] = '0';
			}
		x++;	
		i++;
		}
		y = 0;
		i = 0;
		while(i<=3)
		{
			if(rowleft[i] == '4')
			{
				coordenadas[y][0] = '1';
			}
			else
			{
				coordenadas[y][0] = '0';
			}
		y++;	
		i++;
		}
		y = 0;
		i = 0;
		while(i<=3)
		{
			if(rowright[i] == '4')
			{
				coordenadas[y][3] = '1';
			}
			else
			{
				coordenadas[y][3] = '0';
			}
		y++;	
		i++;
		}

		for(int i=0; i < 4; i++){
			for(int j=0;  j< 4; j++){
				write(1,&coordenadas[i][j],1);
						

			}write(1,"\n",1);
		}

	}
		
}


