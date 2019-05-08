/*
*
* Problema UVA 10300 - Ecological Premium
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, farmers;
	long long int i, j, k, sum;

	scanf("%d\n", &cases);

	while(cases--){
		sum = 0;
		scanf("%d\n", &farmers);

		while(farmers--){
			scanf("%lli %lli %lli\n", &i, &j, &k);
			sum += (i * k);
		}
		printf("%lli\n", sum);
	}


	return 0;
}