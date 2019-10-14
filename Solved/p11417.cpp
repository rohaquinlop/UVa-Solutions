/*
*
* Problema UVa 11417 - GCD
*
*/
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a%b);
}

int main(){
	int n, i, j, res;

	while( scanf("%d", &n) == 1 ){
		if( n == 0 )
			break;
		else{
			res = 0;
			for(i = 1; i < n; i++)
				for(j = i+1; j <= n; j++)
					res += gcd(i, j);

			printf("%d\n", res);
		}
	}

	return 0;
}