/*
*
* Problema UVA 11547 - Automatic Answer
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int cases, n, result;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		result = n*567;
		result /= 9;
		result += 7492;
		result *= 235;
		result /= 47;
		result -= 498,
		result = ((result%100) - (result%10))/10;

		printf("%d\n", abs(result));
	}

	return 0;
}