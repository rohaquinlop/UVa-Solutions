/*
*
* Problema UVA 11364 - Optimal Parking
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int cases, stores, i, array[20], min, max, result;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &stores);

		for(i = 0; i < stores; i++){
			scanf("%d", array+i);
		}
		min = array[0];
		max = array[0];

		for(i = 0; i < stores; i++){
			if(array[i] < min){
				min = array[i];
			}else if(array[i] > max){
				max = array[i];
			}
		}

		result = (max-min) * 2;

		printf("%d\n", result);


	}

	return 0;
}