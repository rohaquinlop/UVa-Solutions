/*
*
* Problema UVA 12372 - Packing for Holiday
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, c = 0, l, w, h;

	scanf("%d", &cases);

	while(cases--){
		c++;
		scanf("%d %d %d", &l, &w, &h);
		if( l <= 20 && w <= 20 && h <= 20 ){
			printf("Case %d: good\n", c);
		}else{
			printf("Case %d: bad\n", c);
		}
	}

	return 0;
}