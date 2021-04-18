/*
*
* Problema UVA 11805 - Bafana Bafana
*
*/

#include <stdio.h>

int main(){
	int cases, n, k, p, c = 0, val;

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		scanf("%d %d %d\n", &n, &k, &p);

		val = (p+k);

		while( val > n ){
			val -= n;
		}
		
		printf("Case %d: %d\n", c, val);

	}

	return 0;
}