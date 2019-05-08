/*
*
* Problema UVA 735 - Dart-a-Mania
*
* Explicación: El problema solicita reducir a un puntaje dado y mostrar cuantas combinaciones y permutaciones tiene. En
* un juego de dardos cada persona consta de un puntaje que se va reduciendo a medida que se lanzan los dardos
* (son 3 dardos), estos dardos al caer pueden tomar valores desde 1 hasta 20, sin embargo, se puede duplicar o triplicar
* los valores de cada dardo al caer, y la suma de los valores de los 3 dardos lanzados se restan del puntaje del usuario.
* Entonces, para solucionar este problema se crea un arreglo con todos los posibles valores que puede tomar un dardo al
* ser lanzado, que son los numeros desde el 0 (0 indica que la persona falló el tiro) hasta 20 (valor máximo en donde
* caen los dardos) y estos numeros se multiplican por 2 y por 3, estos numeros almacenan en un arreglo, tambien existe
* la posibildad que un dardo tome el valor de 50 pero este no se puede duplicar o triplicar, por lo que solo se agrega
* al final del arreglo. Como se lanzan 3 dardos entonces se recorre el arreglo con 3 ciclos anidados para poder
* saber cuantas permutaciones existen y se suman las posiciones del arreglo con los indices que tome i, j y k, y en caso
* que al restarse al puntaje sea igual a cero entonces esa es una permutacion y se incrementa la cantidad de permutaciones
* en 1, para saber si es una combinacion nueva se verifica si el indice del ciclo superior es menor que el indice del
* ciclo inferior así se sabe si esa posicion ya fue tomada y como cada ciclo superior crece más lento que el ciclo inferior
* se puede saber si esa poscion ya fue tomada.
*
* Complejidad: O(43^3)
*/

#include <stdio.h>

int main(){
	int score;
	int i, j, k;
	int nums[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,51,54,57,60,50};
	int comb, perm;
	int diff;

	while( scanf("%d", &score) == 1 ){
		if( score <= 0 ){
			break;
		}else{
			comb = 0;
			perm = 0;

			if( score > 180 ){
				printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
			}else{
				for(i = 0; i < 43; i++){
					for(j = 0; j < 43; j++){
						for(k = 0; k < 43; k++){
							diff = nums[i] + nums[k]+ nums[j];
							if( score-diff == 0 ){
								perm++;

								if( k >= j && j >= i ){
									comb++;
								}
							}
						}
					}
				}

				if(!perm){
					printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
				}else{
					printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, comb);
					printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perm);
				}
			}

			printf("**********************************************************************\n");

		}
	}
	printf("END OF OUTPUT\n");


	return 0;
}
