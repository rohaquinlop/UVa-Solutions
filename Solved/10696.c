/*
*
* Problema UVA 10696 - f91
*
*/

#include <stdio.h>
#include <stdlib.h>

long int f91(long int n){
	long int a;
	if( n >= 101 ){
		return n-10;
	}else{
		a = f91(n+11);
		return f91(a);
	}
}

int main(){
	long long int n, result;

	while( scanf("%lli", &n) == 1 ){
		if( n == 0 ){
			break;
		}else{
			result = f91(n);
			printf("f91(%lli) = %lli\n", n, result);
		}
	}
		
	return 0;
}