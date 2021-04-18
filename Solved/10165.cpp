/*
*
* Problema UVa 10165 - Stone Game
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i, nimVal, aux;

	while( scanf("%d", &n) == 1 ){
		if( n == 0 ) break;
		nimVal = 0;

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			nimVal ^= aux;
		}

		nimVal != 0 ? printf("Yes\n") : printf("No\n");

	}

	return 0;
}