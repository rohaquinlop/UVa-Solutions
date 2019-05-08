/*
*
* Problema UVA 957 - Popes
*
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	long int period, cant, i, j, aux, tPopes, fYear, lYear;
	long int index, increments;

	while( scanf("%li", &period) == 1 ){
		scanf("\n%li\n", &cant);

		long int popes[cant];

		for(i = 0; i < cant; i++){
			scanf("%li\n", &aux);
			popes[i] = aux;
		}

		tPopes = 0;

		for(i = 0; i < cant; i++){
			increments = 0;
			for( j = i; popes[j] <= (popes[i] + period-1); j++){
				increments++;
			}

			if( increments > tPopes ){
				tPopes = increments;
				fYear = popes[i];
				lYear = popes[j-1];
			}
		}

		printf("%li %li %li\n", tPopes, fYear, lYear);

	}


  return 0;
}
