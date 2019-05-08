/*

Problema UVA 100 | 3n + 1

*/

#include <stdio.h>

int main(){
	int i, j;
	int high, low, count;
	int actLenght, maxLength;
	int number;

	while(scanf( "%i %i", &i, &j ) == 2 ){
		maxLength = 1;
		if(i > j){
			high = i;
			low = j;
		}else{
			high = j;
			low = i;
		}

		for(count = 0; count <= (high - low); count++){
			actLenght = 1;
			number = low+count;
			if( number != 1 ){
				while(number != 1){
					actLenght++;
					if( number%2 == 0 ){
						number = number/2;
					}else{
						number = (3*number) + 1 ;
					}
				}
			}

			if(actLenght >= maxLength){
				maxLength = actLenght;
			}
		}

		printf("%i %i %i\n", i, j, maxLength);
	}

	return (0);
}