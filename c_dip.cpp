#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/**
 * play - start round
 *
 * Return: Anything
 */
char word[32],w1[32],w2[32];
int t,t2,t1;
int play()
{
	char c;
	int  len = 0, i, n = 0, h = 0;
	t=5;
	int score = 0;

	printf("Inserta la palabra a adivinar: ");
	scanf(" %s", word);
	len = strlen(word);
	
	system("cls");

	char hide[len];
	for (i = 0; i < len; i++)
		hide[i] = '-';
	hide[i] = '\0';

	while (t && h != len)
	{
		printf("Palabra oculta: %s\n", hide);
		printf("Intentos: %d\n", t);
		printf("Puntos: %d\n", t * 10);
		printf("Inserte una letra: ");
		scanf(" %c", &c);
		for (i = 0; i < len; i++)
		{
			if (word[i] == c)
			{
				printf("%s\n", hide);
				n = 1;
				if (hide[i] == '-')
				{
					hide[i] = c;
					 h++;
				}
				else
				{
					system("cls");
					printf("La letra ya ha sido usada\n");
					break;
				}
			}
			system("cls");
		}
		if (n)
			n = 0;
		else
			t--;
	}
	if (t == 0)
	{
		score = 0;
		printf("Oh no, intentalo de nuevo\n");
	}
	else if (h == len)
	{	
		score = t * 10;
		printf("Felicitaciones\n");
	}
	printf("La palabra era %s\n\n", word);
	return (score);
}
void welcome()
{
	system("cls");		
	printf("***************\n");
	printf("\t Bienvenidos al juego adivina la palabra\n");
	printf("***************\n\n\n");
	
	printf("- OBJETIVO DEL JUEGO\n\n");
	printf("El jugador debera descifrar la palabra secreta.\n\n\n");
	
	printf("- COMO JUGAR?\n\n");
	printf("El juego empieza con el jugador 1 escribiendo la palabra oculta\n");
	printf("El jugador 2 elegira una letra y la ingresara con el teclado.\n");
	printf("Si dicha letra esta en la palabra, la mostrara en el espacio destinado para esta\n");
	printf("de lo contrario se le restara una unidad al numero de intentos.\n");
	printf("El jugador 2 podra ver las letras que ya fueron ingresadas.\n");
	printf("El jugador 2 tendra 5 intentos para descubrir la palabra.\n");
	printf("Despues sera el turno del jugador 1 de descubrir la palabra.\n\n\n");
	printf("\nPresiona la tecla ENTER para empezar a jugar ");
	getchar();
}
/**
 * main - entry point
 *
 * Return 0 if success
 */
int main()
{
	FILE *archivo;
	archivo=fopen("record.txt", "a");
	fprintf(archivo,"........................................\n");
	
	int pl = 1, sc_1 = 0, sc_2 = 0, player = 1;
	char pl1[10],pl2[10];

    printf( "Introduzca el nombre del jugador 1: " );
    scanf( "%s", pl1 );
    
    printf( "Introduzca el nombre del jugador 2: " );
    scanf( "%s", pl2 );
  
	
	welcome();

	
	while (pl)
	{
		system("cls");
		printf("Jugador %s tendra que adivinar la palabra, preparese\n", pl2);
		printf("Jugador %s escribe la palabra a continuacion\n", pl1);
		
		sc_1 += play();
		t1=t;
		fprintf(archivo, "word: %s \t",word);
		
		printf("Jugador %s tendra que adivinar la palabra, preparese\n", pl1);
		printf("Jugador %s escribe la palabra a continuacion\n", pl2);
		
		sc_2 += play();
		t2=t;
		fprintf(archivo, "word: %s \n",word);	
		
		printf("Desean seguir jugando? (1 para seguir, 0 para salir): ");
		scanf(" %d", &pl);
	}
	if (sc_1 == sc_2)
		printf("Han empatado\n\n");
	else if (sc_1 > sc_2)
		printf("Jugador %s ha ganado\n\n", pl1);
	else if (sc_2 > sc_1)
		printf("Jugador %s ha ganado\n\n", pl2);
	printf("Puntaje del jugador %s : %d\n",pl1 , sc_1);
	printf("Puntaje del jugador %s : %d\n",pl2, sc_2);
	

	
	fprintf(archivo, "name: %s \t",pl1);
	fprintf(archivo, "name: %s \n",pl2);
	fprintf(archivo, "score: %d \t",sc_1);
	fprintf(archivo, "score: %d \n",sc_2);
	fprintf(archivo, "attemps: %d \t",t1);
	fprintf(archivo, "attemps: %d \t\n\n\n",t2);
	fclose(archivo);
	system("pause");
	return (0);

}

