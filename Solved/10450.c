/*
*
* Problema UVA 10450 - World Cup Noise
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fib(int n){
	double iotta, val;

	iotta = (1 + sqrt(5) )/2;

	val = pow(iotta, n+1) - ( 1/pow(-iotta, n+1) );

	val /= sqrt(5);

	return val;
}

int main(){
	int cases, c = 0, n;

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		scanf("%d", &n);

		printf("Scenario #%d:\n%.0lf\n\n", c, fib(n+1));
	}


	return 0;
}