#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check(char *str);
void	rush01(char *str);
void	print_array(char coordenadas[4][4]);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	} 
	int result = 0;
	result = check(argv[1]);
	if (result == 1)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	rush01(argv[1]);
	return (0);
}

int check(char *str)
{
	//si todo esta bien devuelve 1
	int i = 0;
	int cont = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '4')
		{ //comprobamos que no hay mas de 2 cuatros
			cont++;
			if (cont > 2)
			{
				printf("demasiados 4");
				return 1;
			}
		}
		if ((str[i] < '1' || str[i] > '4') && i % 2 == 0) 
		//comprobamos que los numeros van del 1-5
		{
			printf("%c", str[i]);
			return 1;
		}
		i++;
	}
	if (i != 31)
	{ //31 por la ultima iteracion
		printf("demasiados char");
		return 1;
	}
	return 0;
}

void chk_set(char set[4])
{
	//Comprobamos que no haya más de un 4 o un 1 en cada set
	int i = 0;
	int cont4 = 0;
	int cont1 = 0;
	while (i < 4)
	{
		if (set[i] == '4')
		{
			cont4++;
			if (cont4 > 1)
			{
				write(1, "Error", 5);
				write(1, "\n", 1);
				exit (1);
			}
		}
		if (set[i] == '1')
		{
			cont1++;
			if (cont1 > 1)
			{
				write(1, "Error", 5);
				write(1, "\n", 1);
				exit (1);
			}
		}
		i++;
	}
}

void org_cols(char colup[4], char coldown[4], char *str)
{
	//Organizamos los dos primeros sets de entrada en las columnas de arriba y de abajo :)
	int i = 0;
	int j = 0;
	while (i < 15)
	{
		if (i <= 6)
			colup[j] = str[i];
		else if (i >= 8 && i <= 14)
		{
			if (i == 8)
				j = 0;
			coldown[j] = str[i];
		}

		j++, i += 2;
	}
}

void org_rows(char rowleft[4], char rowright[4], char *str)
{
	//Organizamos los dos últimos sets de entrada en las filas de izquierda y derecha :)
	int i = 16;
	int j = 0;
	while (i < 31)
	{
		if (i >= 16 && i <= 22)
		{
			if (i == 16)
				j = 0;
			rowleft[j] = str[i];
		}
		else if (i >= 24 && i <= 30)
		{
			if (i == 24)
				j = 0;
			rowright[j] = str[i];
		}
		j++, i += 2;
	}
}

void fill_array(char coordenadas[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			coordenadas[i][j] = '0';
			j++;
		}
		i++;
	}
}

int rev(char fila_columna1, char fila_columna2, char c1, char c2)
{
	if (fila_columna1 != c2 && fila_columna2 == c1)
	{
		return 1;
	}
	else if (fila_columna1 == c2 && fila_columna2 == c1)
	{
		return 0;
	}
	return 1;
}

void rush01(char *str)
{
	char colup[4];
	char coldown[4];
	char rowleft[4];
	char rowright[4];

	org_cols(colup, coldown, str), org_rows(rowleft, rowright, str);
	chk_set(colup), chk_set(coldown), chk_set(rowleft), chk_set(rowright);

	//Comprobacion de que con los valores dados hay solución
	int x = 0;
	int y = 0;

		while(x<=3 && y<=3)
	{
		if((rowleft[x] == '4' && rowright[y] != '1') || (rowleft[x] != '1' && rowright[y] == '4')){ 
			write(1, "Error", 5);
			write(1, "\n", 1);
			exit (1);
		}
		x++;
		y++;
		
}

	//INICIALIZAMOS TODO EL ARRAY BIDIMENSIONAL A CERO
	char coordenadas[4][4];
	fill_array(coordenadas);

	int cont = 0;
	int j;
	int i;
	int cont2 = 0;
	int cont3 = 0;
	int z = 0;
	int t = 0;
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	
	while (z <= 3 && t <= 3)
	{
		i = 0, j = 0;
		x = 0, y = 0;
		while (x <= 3 && y <= 3)
		{
			while (i <= 3 && j <= 3)
			{
				cont = 0;
				//comprobamos si son iguales izq y derecha, y arriba y abajo
				if ((rowleft[i] == '4' && rowright[i] == '1')) //se tienen que cumplir ambas condiciones
				{

					while (cont < 4)
					{
						coordenadas[cont][j] = cont + 49;
						coordenadas[i][cont] = cont + 49;
						cont++;
					}
				}

				if ((rev(rowleft[i], rowright[i], '4', '1') == 0)) //se tienen que cumplir ambas condiciones
				{
					int cont2 = 53;
					int cont3 = 53;
					while (cont < 4)
					{
						coordenadas[j][cont] = cont2 -= 1;
						coordenadas[cont][i] = cont3 -= 1;
						cont++;
					}
				}

				if (colup[j] == '4' && coldown[j] == '1')
				{
					while (cont < 4)
					{
						coordenadas[cont][j] = cont + 49;
						cont++;
					}
				}
				if ((rev(colup[j], coldown[j], '4', '1') == 0))
				{
					cont2 = 53;
					cont3 = 53;
					while (cont < 4)
					{
						coordenadas[cont][j] = cont3 -= 1;
						cont++;
					}
				}

				if ((rowleft[i] == '3' && rowright[i] == '2'))
				{
					//3-2 TIENE 2341 1243 1342 TERCERA POSICION SIEMPRE 4
					if (coordenadas[i][0] == '2') //si es 3-2  y empieza por 2 la fila puede ser solo 2341
					{
						coordenadas[i][1] = '3';
						coordenadas[i][2] = '4';
						coordenadas[i][3] = '1';
					}

					if (coordenadas[0][j] == '2')
					{
						coordenadas[1][j] = '3';
						coordenadas[2][j] = '4';
						coordenadas[3][j] = '1';
					}
					else if (coordenadas[i][j] == '2')
					{
						coordenadas[2][3] = '3';
						coordenadas[1][3] = '4';
						coordenadas[0][3] = '1';
					}

					else if (coordenadas[i][0] == '1')
					{
						coordenadas[i][1] = '3';
						coordenadas[i][2] = '4';
						coordenadas[i][3] = '2';
					}
					else
					{
						coordenadas[i][j] = '4'; //en caso de que no empiece por 2 ponemos el 4 en la tercera posicion
					}
				}

				if (colup[j] == '3' && coldown[j] == '2')
				{
				}

				else if ((rowleft[i] == '2' && rowright[i] == '3') || (colup[j] == '3' && coldown[j] == '2'))
				{
					if (coordenadas[3][2] == '2') //si es 2-3  y empieza por 2 la fila puede ser 2413
					{
						coordenadas[2][i] = '3';
						coordenadas[1][2] = '4';
						coordenadas[0][2] = '1';
					}
					if (coordenadas[3][2] == '1') //si es 2-3  y empieza por 1 la fila puede ser o 1432 
					{
						coordenadas[2][2] = '4';
						coordenadas[1][2] = '3';
						coordenadas[0][2] = '2';
					}
					
				}
				else if ((rowleft[i] == '2' && rowright[i] == '2') || (colup[j] == '2' && coldown[j] == '2'))
				{
					//si entra un 2-2  tiene que haber un 3 en una esquina
					if (coordenadas[3][i] == '3')
					{
						coordenadas[2][i] = '4';
						coordenadas[1][i] = '1';
						coordenadas[0][i] = '2';
					}

					if (coordenadas[j][0] == '3' && coordenadas[j][1] == '4')
					{
						coordenadas[j][2] = '1';
						coordenadas[j][3] = '2';
					}
					if (coordenadas[0][i] == '3' && coordenadas[1][i] == '4')
					{
						coordenadas[2][i] = '1';
						coordenadas[3][i] = '2';
					}
					if (coordenadas[0][i] == '2' && coordenadas[3][1] == '3')
					{
						coordenadas[1][i] = '1';
						coordenadas[2][i] = '4';
					}
					if (coordenadas[2][0] == '2' && coordenadas[2][1] == '4')
					{
						coordenadas[2][2] = '1';
						coordenadas[2][3] = '3';
					}
				}
				if ((rowleft[i] == '1' && rowright[i] == '2') || (colup[j] == '1' && coldown[j] == '2'))
				{
					if (coordenadas[j][0] == '4')
					{
						coordenadas[j][3] = '3';
					}
					if (coordenadas[j][i] == '4')
					{
						coordenadas[j][i + 3] = '3';
					}

					if (coordenadas[0][i] == '4')
					{
						coordenadas[3][i] = '3';
					}
					if (coordenadas[j][0] == '4' && coordenadas[j][1] == '1')
					{
						coordenadas[j][2] = '2';
					}
					if (coordenadas[0][i] == '4' && coordenadas[1][i] == '1')
					{
						coordenadas[2][i] = '2';
					}
				}
				if ((rowleft[i] == '2' && rowright[i] == '1') || (colup[j] == '2' && coldown[j] == '1'))
				{
					if(coordenadas[3][3] == '4')
					{
						coordenadas[0][0] = '3';
					}
					if(coordenadas[3][0] == '4')
					{
						coordenadas[0][0] = '3';
					}
					if(coordenadas[0][3] == '4' && coordenadas[0][2] == '1')
					{
						coordenadas[0][1] = '2';
					}
					if(coordenadas[0][i] == '4')
					{
						coordenadas[i][i-2] = '3';
					}
					if(coordenadas[0][0] == '3' && coordenadas[3][0] == '4')
					{
						coordenadas[1][0] = '2';
						coordenadas[2][0] = '1';
					}
					if(coordenadas[1][0] == '3' && coordenadas[1][1] == '1')
					{
						coordenadas[1][2] = '2';
						coordenadas[2][3] = '4';
					}
					if(coordenadas[3][2] == '4')
					{
						coordenadas[0][2] = '3';
					}
				}

				i++;
				j++;
			}
			x++;
			y++;
		}
		z++;
		t++;
	}
	print_array(coordenadas);
}

void print_array(char coordenadas[4][4])
{
	int i = 0;
	int j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &coordenadas[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
