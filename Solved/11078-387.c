/*
*
* Problema UVA 11078 - Open Credit System
*
*/

#include <stdio.h>
#include <math.h>

int main(){
	int cases;
	int n, i, higher, maxDif;
	int array[100001];

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		higher = -300000;
		maxDif = higher;

		for(i = 0; i < n; i++){
			scanf("%d", &array[i]);
			if(i > 0){
				if( array[i-1] > higher ){
					higher = array[i-1];
				}
				if( higher-array[i] > maxDif ){
					maxDif = higher-array[i];
				}
			}
		}

		printf("%d\n", maxDif);

	}


	return 0;
}
