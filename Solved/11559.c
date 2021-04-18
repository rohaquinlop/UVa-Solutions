/*
*
* Problema UVA 11559 - Event Planning
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	long int nPart, hotels, weeks;
	long int budget, sum, aux;
	long int array[18][14], i, j, find;

	while( scanf("%li %li %li %li", &nPart, &budget, &hotels, &weeks) == 4 ){
		i = 0;
		sum = 2000000;
		while(hotels--){
			scanf("%li", &array[i][0]);
			for(j = 1; j <= weeks; j++){
				scanf("%li", &array[i][j]);
				if( array[i][j] >= nPart ){
					aux = array[i][0] * nPart;
					if( sum >= aux){
						sum = aux;
					}
				}
			}
			i++;
		}
		if(sum <= budget){
			printf("%li\n", sum);
		}else{
			printf("stay home\n");
		}
	}


	return 0;
}