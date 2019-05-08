/*
*
* Problema UVA 102 - Ecological Bin Packing
*
* Explicacion: El problema da la información de 3 contenedores, cada uno lleva 3 espacios en ellos que almacenan botellas de colores
* (cafe, verde y transparente) en el orden dado, e indica la cantidad de botellas que hay en cada uno. Para solucionar el
* problema se debe dejar todas las botellas de un solo color en un solo contenedor por ejemplo, si el primer contenedor
* tiene las botellas de color café ningun otro contenedor puede tener las botellas de ese mismo color. Además a esto,
* se debe decir cual fue la configuración u orden que se empleo BCG, BGC, etc, la primera configuración (BCG) indica que
* en el primer contenedor están las boteelas de color café, en el segundo, estan las de color transparente, y en el tercero
* las de color verde. Entonces para solucionar este problema lo que se hace es probar cada combinación (greedy) y así
* mismo se sabe cual es el orden que optimiza el movimiento de botellas.
* 
* Complejidad: T(6) O(1), es constante, ya que se recorren todas las posibles combinaciones que son 6 y se toma la menor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 2147483647

int main(){
	int array[3][3];
	int comb[6];
	int i, posI, min;
	char *letters[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

	while( scanf("%d %d %d %d %d %d %d %d %d\n", &array[0][0], &array[0][1], &array[0][2], &array[1][0], &array[1][1], &array[1][2], &array[2][0], &array[2][1], &array[2][2]) != EOF ){

		/* Combinacion BGC */
		comb[0] = array[0][1]+array[0][2] + array[1][0]+array[1][1] + array[2][0]+array[2][2];
		comb[1] = array[0][1]+array[0][2] + array[1][0]+array[1][2] + array[2][0]+array[2][1];
		comb[2] = array[0][0]+array[0][1] + array[1][1]+array[1][2] + array[2][0]+array[2][2];
		comb[3] = array[0][0]+array[0][1] + array[1][0]+array[1][2] + array[2][1]+array[2][2];
		comb[4] = array[0][0]+array[0][2] + array[1][1]+array[1][2] + array[2][0]+array[2][1];
		comb[5] = array[0][0]+array[0][2] + array[1][0]+array[1][1] + array[2][1]+array[2][2];

		min = MAXVAL;

		for(i = 0; i < 6; i++){
			if( comb[i] < min ){
				min = comb[i];
				posI = i;
			}
		}

		printf("%s %d\n", letters[posI],min);

	}

	return 0;
}
