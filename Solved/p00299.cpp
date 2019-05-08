/*
*
* Problema UVA 299 - Train Swapping
*
*/

#include <stdio.h>
#include <iostream>

int main(){
	int cases;
	int length;
	int train[50];
	int i, j, aux;
	int swaps, moves;

	scanf("%d\n", &cases);

	while(cases--){
		scanf("%d\n", &length);
		for(i = 0; i < length; i++){
			scanf("%d", &train[i]);
		}

		swaps = 0;

		for(i = 1 ; i < length; i++){
			aux = train[i];
			j = i-1;
			moves = 0;
			while( j >= 0 && train[j] > aux ){
				train[j+1] = train[j];
				j--;
				moves++;
				swaps++;
			}
			train[j+1] = aux;
		}

		printf("Optimal train swapping takes %d swaps.\n", swaps);
	}


	return 0;
}