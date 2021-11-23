

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//void rush01 (char *str);
int check(char *str);
void rush01 (char *str);
void imprimo (char coordenadas[4][4]);
void recorro (char coordenadas[4][4]);

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
	rush01("1 2 2 2 4 2 1 3 1 2 2 3 3 1 2 2");
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

int reverse(char fila_columna1, char fila_columna2, char c1, char c2)
{
	if (fila_columna1 != c2 && fila_columna2 == c1){
		return 1;
	}
	else if (fila_columna1 == c2 && fila_columna2 == c1)
	{
	return 0;
	}
	return 1;
}

void rush01 (char *str)
{
	int i = 0;
	int j = 0;
	char colup[4];
	char coldown[4];
	char rowleft[4];
	char rowright[4];
//bucle que organiza el string metido por parametro en columnas y filas(enunciado)
while (i<31) 
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

//Comprobacion de que con los valores dados hay solución
	int x = 0;
	int y = 0;	
	
/*	while(x<=3 && y<=3)
	{
		if((rowleft[x] == '4' && rowright[y] != '1') || (rowleft[x] != '1' && rowright[y] == '4')){
			write(1, "Error", 5);
			write(1, "\n", 1);
			exit (1);
		}
		//si es 3 pero no va ni con 3 ni con 2 error, creamos reverse para el opuesto
		else if( ((rowleft[x] == '3' && rowright[y] != '2')
			&& (rowleft[x] == '3' && rowright[y] != '1')) || (reverse(rowleft[x],rowright[y],'3','1' )==1))
		{
			write(1, "Error", 5);
			write(1, "\n", 1);
			exit (1);
		}
		
		x++;
		y++;
}*/


char coordenadas[4][4];
//INICIALIZAMOS TODO EL ARRAY BIDIMENSIONAL A CERO
	for( i=0; i < 4; i++){
			for( j=0;  j< 4; j++){
					coordenadas[i][j]='0';
				}
	}
	int cont=0;
	j = 0;
	i = 0;
	x = 0;
	y = 0;
	int cont2 = 0;
	int cont3 = 0;
	i=0,j=0;
	int z=0,t=0;
	while(z<=3 && t<=3){
	i=0,j=0;
	x=0,y=0;
	while(x<=3 && y<=3)
	{
		while(i<=3 && j<= 3)
		{
			cont = 0;
			//comprobamos si son iguales izq y derecha, y arriba y abajo 
			if((rowleft[i] == '4' && rowright[i] == '1')) //se tienen que cumplir ambas condiciones
			{
				
				while (cont <4)
				{
					coordenadas[cont][j] = cont + 49;
					coordenadas[i][cont] = cont + 49;
					cont++;
				}
			}			

			if((reverse(rowleft[i], rowright[i], '4', '1')==0 )) //se tienen que cumplir ambas condiciones
			{ 
					int cont2 = 53;
					int cont3 = 53;
					while (cont <4)
					{
						coordenadas[j][cont] = cont2 -= 1;
						coordenadas[cont][i] = cont3 -= 1;
						cont++;
					}
			}
			
			if (colup[j] == '4' && coldown[j] == '1' )
			{
				while (cont <4)
				{
					coordenadas[cont][j] = cont + 49;
					//coordenadas[i][cont] = cont + 49;
					cont++;
				}
			}
			if((reverse(colup[j], coldown[j], '4', '1')==0 ))
			{
					cont2 = 53;
					cont3 = 53;
					while (cont <4)
					{
						coordenadas[cont][j] = cont3 -= 1;
						cont++;
					}
			}

			//CONDICIONES PARA QUE SIEMPRE QUE HAYA UN 1 PONGA UN 4
			if(rowleft[i] == '1') 
			{
				//coordenadas[i][cont] = '4';
			}
			else if(rowright[i] == '1') 
			{
				//coordenadas[3][0] = '4'; //mirar ese 3
			}
			else if(colup[j] == '1')
			{
				//coordenadas[cont][j] = '4';
			}
			else if(coldown[j] == '1') 
			{
				//coordenadas[cont][j] = '4';
			}


			if((rowleft[i] == '3' && rowright[i] == '2') ) // NO ES LO MISMO 3-2  QUE 2-3
			{
					//3-2 TIENE 2341 1243 1342 TERCERA POSICION SIEMPRE 4
					if(coordenadas[i][0] == '2')  //si es 3-2  y empieza por 2 la fila puede ser solo 2341 
					{
					coordenadas[i][1] = '3';
					coordenadas[i][2] = '4';
					coordenadas[i][3] = '1';
					
					}
					else if(coordenadas[i][0] == '1') 
					{
					coordenadas[i][1] = '3';
					coordenadas[i][2] = '4';
					coordenadas[i][3] = '2';
					
					}
				/*	else
					{
					 //en caso de que no empiece por 2 ponemos el 4 en la tercera posicion ¿funciona?
					}*/
				/*	if(i==0)
						coordenadas[i][i+2] = '4';
					else if(i==3)
						coordenadas[i][i-2] = '4';*/
					
			}

			if(colup[j] == '3' && coldown[j] == '2')
			{
					if(coordenadas[0][j] == '2')
					{
					coordenadas[1][j] = '3';
					coordenadas[2][j] = '4';
					coordenadas[3][j] = '1';
					}
					else if(coordenadas[3][j] == '2'){
					coordenadas[2][j] = '3';
					coordenadas[1][j] = '4';
					coordenadas[0][j] = '1';
					}
					/*if(j==0)
						coordenadas[j+2][j] = '4';
					else if(j==3)
						coordenadas[j-2][j] = '4';*/
			}

			else if(reverse(rowleft[i], rowright[i], '3', '2')==0) // // NO ES LO MISMO 3-2  QUE 2-3  && (|| (colup[j] == '2' && coldown[j] == '3' ) esta condicion habria que tratarla aparte)
			{
					
					if(coordenadas[3][2] == '1') //si es 2-3  y empieza por 2 la fila puede ser o 1432 3421 2413
					{
						coordenadas[2][2] = '4';
						coordenadas[1][2] = '3';
						coordenadas[0][2] = '2';
					}
					if(coordenadas[3][2] == '2') //si es 2-3  y empieza por 2 la fila puede ser o 1432 3421 2413
					{
						coordenadas[2][2] = '3';
						coordenadas[1][2] = '4';
						coordenadas[0][2] = '1';
					}
					//2-3 TIENE 2431 3421 1432  segunda posicion SIEMPRE 4 */
					/*if(i==0)
						coordenadas[i][i+2] = '4';
					else if(i==3)
						coordenadas[i][i-2] = '4';*/
			}
			
			if (reverse(colup[j], coldown[j], '3', '2')==0)
			{
				
					if(coordenadas[0][j] == '2')
					{
					coordenadas[1][j] = '3';
					coordenadas[2][j] = '4';
					coordenadas[3][j] = '1';
					}
					else if(coordenadas[3][j] == '2'){
					coordenadas[2][j] = '3';
					coordenadas[1][j] = '4';
					coordenadas[0][j] = '1';
					}
					if(j==0)
						coordenadas[j+2][j] = '4';
					else if(j==3)
						coordenadas[j-2][j] = '4';
			}
			else if((rowleft[i] == '2' && rowright[i] == '2') || (colup[j] == '2' && coldown[j] == '2' )) // // NO ES LO MISMO 3-2  QUE 2-3  && (|| (colup[j] == '2' && coldown[j] == '3' ) esta condicion habria que tratarla aparte)
			{
					//si entra un 2-2  tiene que haber un 3 en una esquina, PROBLEMA principio o final? 2413 1243 3412
					if(coordenadas[3][i] == '3')
					{
						coordenadas[2][i] = '4';
						coordenadas[1][i] = '1';
						coordenadas[0][i] = '2';
					}

					if(coordenadas[j][0] == '3' && coordenadas[j][1] == '4')
					{
						coordenadas[j][2] = '1';
						coordenadas[j][3] = '2';
					}
					if(coordenadas[0][i] == '3' && coordenadas[1][i] == '4')
					{
						coordenadas[2][i] = '1';
						coordenadas[3][i] = '2';
					}
					if(coordenadas[0][i] == '2' && coordenadas[3][1] == '3')
					{
						coordenadas[1][i] = '1';
						coordenadas[2][i] = '4';
					}
					if(coordenadas[2][0] == '2' && coordenadas[2][1] == '4')
					{
						coordenadas[2][2] = '1';
						coordenadas[2][3] = '3';
					}
				
			}
			if((rowleft[i] == '1' && rowright[i] == '2') || (colup[j] == '1' && coldown[j] == '2' )) // // NO ES LO MISMO 3-2  QUE 2-3  && (|| (colup[j] == '2' && coldown[j] == '3' ) esta condicion habria que tratarla aparte)
			{
					//si entra un 2-2  tiene que haber un 3 en una esquina, PROBLEMA principio o final?
					if(coordenadas[j][0] == '4')
					{
						coordenadas[j][3] = '3';
					}
					if(coordenadas[j][i] == '4')
					{
						coordenadas[j][i+3] = '3';
					}
					
					if(coordenadas[0][i] == '4')
					{
						coordenadas[3][i] = '3';
					}
					if(coordenadas[j][0] == '4' && coordenadas[j][1] == '1')
					{
						coordenadas[j][2] = '2';
					}
					if(coordenadas[0][i] == '4' && coordenadas[1][i] == '1')
					{
						coordenadas[2][i] = '2';
					}
			}
			//PROBLEMA NO PUEDE SABERLO YA QUE LA CONDICION DE QUE EL PRIMERO SEA 4 SE HACE AL FINAL
			 if((rowleft[i] == '2' && rowright[i] == '1') || (colup[j] == '2' && coldown[j] == '1' )) // // NO ES LO MISMO 3-2  QUE 2-3  && (|| (colup[j] == '2' && coldown[j] == '3' ) esta condicion habria que tratarla aparte)
			{
					//si entra un 2-2  tiene que haber un 3 en una esquina, PROBLEMA principio o final?
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
	imprimo (coordenadas); //imprimimos el array bidimensional
	recorro (coordenadas);
}

//imprimimos el array bidimensional
void imprimo (char coordenadas[4][4])
{
	for(int i=0; i < 4; i++){
			for(int j=0;  j< 4; j++){
				if(coordenadas[i][j]!='0'){
				write(1,&coordenadas[i][j],1);
				write(1," ",1);
				}else{
					coordenadas[i][j]='0';
					write(1,&coordenadas[i][j],1);
					write(1," ",1);
				}

			}
			write(1,"\n",1);
	}
}


void recorro (char coordenadas[4][4])
{
	int i = 0, j=0, h=0;
	int repex = '0';
	int repey = '0';
	
	while(j<4){

		if(j<3) //comprobamos hasta que llegue a 3
		{
			//comprobamos 00 con 01 con 02 con 03 y luego pasariamos a 01 con 02 con 03 y ...
			if(coordenadas[i][h] == coordenadas[i][j+1]) // es en el que estoy igual que el siguiente? si
			{
				repex++;
			}
			j++;
		}
		//siempre que sea 3 la j reseteamos para pasar al siguiente
		if(j==3)
		{
			h+=1;
			j=h;
		}
		//una vez ya tenemos hecho toda la fila 00 tenemos que pasar a la 10
		//i++;
		
	}
	write(1,&repex,1);
	
	j=0;
	h=0;
	i=0;
	while(i<4){

		if(i<3) //comprobamos hasta que llegue a 3
		{
			//comprobamos 00 con 10 con 20 con 30 y luego pasariamos a 01 con 11 con 21 con 31 y ...
			if(coordenadas[h][j] == coordenadas[i+1][j]) // es en el que estoy igual que el siguiente? si
			{
				repey++;
			}
			i++;
		}
		//siempre que sea 3 la i reseteamos para pasar al siguiente
		if(i==3){
			h+=1;
			i=h;
		}
		//una vez ya tenemos hecho toda la fila 00 tenemos que pasar a la 01
		//j++;
	}
	write(1,&repey,1);
}