/*
*
* Problema UVA 10035 - Primary Arithmetic
*
*/

#include <stdio.h>
#include <stdlib.h>

int carry(int n, int m){
	int c = 0, count = 0, a;

	while( (n >= 0) && (m >= 0) ){
		if( n == 0 && m == 0){
			break;
		}else{
			a = n%10 + m%10 + c;
			n /= 10;
			m /= 10;
			c = 0;
			if( a >= 10 ){
				count++;
				c = a/10;
			}
		}
	}
	return count;
}

int main(){
	int a, b, cOperations;

	while( scanf("%d %d", &a, &b) == 2 ){
		if( a == 0 && b == 0 ){
			break;
		}else{
			cOperations = carry(a, b);

			if( cOperations > 0 ){
				if( cOperations == 1 ){
					printf("%d carry operation.\n", cOperations);
				}else{
					printf("%d carry operations.\n", cOperations);
				}
			}else{
				printf("No carry operation.\n");
			}
		}
	}

	return 0;
}