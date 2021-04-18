/*
*
* Problema UVA 12279 - Emoogle Balance
*
*/

#include <stdio.h>

int main(){
	int cases, i, count, n, t = 0;

	while( scanf("%d", &cases) == 1 ){
		if( cases == 0){
			break;
		}else{
			count = 0;
			t++;
			while(cases--){
				scanf("%d", &n);
				if (n == 0){
					count--;
				}else{
					count++;
				}
			}
			printf("Case %d: %d\n", t, count);
		}
	}


	return 0;
}