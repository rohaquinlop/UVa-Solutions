/*
*
* Problema UVA 11078 - Open Credit System
*
*/

#include <stdio.h>

int main(){
	int cases;
	int n, i, higher, maxDif;
	int ans, act;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		higher = -300000;
		maxDif = higher;

		scanf("%d", &ans);

		for(i = 0; i < n-1; i++){
			scanf("%d", &act);
			if( ans > higher ){
				higher = ans;
			}
			if( higher-act > maxDif ){
				maxDif = higher-act;
			}
			ans = act;
		}

		printf("%d\n", maxDif);

	}


	return 0;
}
