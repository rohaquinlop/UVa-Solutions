/*
*
* Problema UVA 369 - Combinations
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int C(int n, int k){
	if( n == k || k == 0 ){
		return 1;
	}else{
		return C(n-1, k-1) + C(n-1, k);
	}
}

int main(){
	int n, k;

	while( scanf("%d %d", &n, &k) == 2 ){
		if( n == 0 && k == 0 ){
			break;
		}else{
			printf("%d things taken %d at a time is %d exactly.\n", n, k, C(n, k));
		}
	}

	return 0;
}