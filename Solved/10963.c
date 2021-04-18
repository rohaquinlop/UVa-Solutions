/*
*
* Problema UVA 10963 - Swallowing Ground
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, columns, sum, i, j, k, count, band;

	scanf("%d\n", &cases);
	count = 0;

	while(cases--){
		sum = 0;
		scanf("\n%d\n", &columns);

		scanf("%d %d\n", &i, &j);
		sum = i-j;
		band = 1;

		for(k = 0; k <columns-1; k++){
			scanf("%d %d\n", &i, &j);
			if( sum != i-j ){
				band = 0;
			}
		}

		if (count > 0){
			printf("\n");
		}

		if(band == 1){
			printf("yes\n");
			count++;
		}else{
			printf("no\n");
		}
	}

	return 0;
}