/*
*
* Problema UVA 12149 - Feynman
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n, count;

	while( scanf("%d", &n) == 1 ){
		if(n == 0){
			break;
		}else{
			count = 1;

			while( n > 1 ){
				count += n*n;
				n--;
			}

			printf("%d\n", count);
		}
	}

	return 0;
}