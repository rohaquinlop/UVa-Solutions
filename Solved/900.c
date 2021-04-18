/*
*
* Problema UVA 900 - Brick Wall Patterns
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fib(long long int n){
	double iotta, val;

	iotta = (1 + sqrt(5) )/2;

	val = pow(iotta, n+1) - ( 1/pow(-iotta, n+1) ) ;

	val /= sqrt(5);

	return val;
}

int main(){
	long long int n;

	while( scanf("%lli", &n) == 1 ){
		if(n == 0){
			break;
		}else{
			printf("%.0lf\n", fib(n));
		}
	}

	return 0;
}