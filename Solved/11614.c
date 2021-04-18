/*

Problema UVA 11614 | Etruscan Warriors Never Play Chess

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int cases;
	long long int troops;
	long long int rows;
	long long int count;

	scanf("%d", &cases);

	while(cases){
		scanf("%lli", &troops);
		
		if(troops > 0){
			rows = (2*troops) - 1;
			rows = sqrt(rows);

			count = (pow(rows,2)+rows)/2;

			if(troops < count){
				rows--;
			}
			printf("%lli\n", rows);
		}else{
			printf("0\n");
		}


		cases--;
	}

	return 0;
}