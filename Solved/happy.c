/*
*
* Problema HPYNOS - Happy Numbers I
*
*/

#include <stdio.h>
#include <string.h>

int can;
int memo[260];

int reduce(int n){
	int accum = 0;
	while(n){
		accum += (n%10)*(n%10);
		n /= 10;
	}
	return accum;
}

int happy(int n){
	if( n == 1 )
		return can;
	if( memo[n] == 1 )
		can = -1;
	else{
		memo[n] = 1;
		can++;
		happy(reduce(n));
	}
	return can;
}

int main(){
	int num;

	while( scanf("%d", &num) == 1 ){
		memset(memo, -1, sizeof(memo));
		num = reduce(num);
		can = 1;
		if( num == 1 )
			printf("%d\n", can);
		else{
			printf("%d\n", happy(num));
		}
	}

	return 0;
}