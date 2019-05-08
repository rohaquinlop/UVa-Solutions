/*
*
* Problema UVA 11332 - Summing Digits
*
*/

#include <stdio.h>
#include <stdlib.h>

int g(int n){
	int sum;
	while( n >= 10 ){
		sum = 0;

		while( n > 0 ){
			sum += n % 10;
			n /= 10;
		}

		n = sum;
	}

	return n;

}

int main(){
	int c;

	while( scanf("%d\n", &c) ){
		if(c == 0){
			break;
		}else{
			printf("%d\n", g(c) );
		}
	}

	return 0;
}