/*
*
* Problema UVA 11044 - Searching for Nessy
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int cases;
	long int n, m, result;

	scanf("%d\n", &cases);

	while(cases--){
		scanf("%li %li", &n, &m);

		result = floor(n/3) * floor(m/3);
		printf("%li\n", result);

	}

	return 0;
}