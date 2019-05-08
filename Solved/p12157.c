/*
*
* Problema UVA 12157 - Tariff Plan
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int cases, aux, n, i, mile, juice, c = 0;

	scanf("%d\n", &cases);

	while(cases--){
		mile = 0;
		juice = 0;
		c++;

		scanf("%d\n", &n);

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			mile += ( (aux/30)+1 )*10;
			juice += ( (aux/60)+1 )*15;
		}

		if( mile < juice ){
			printf("Case %d: Mile %d\n", c, mile);
		}else if( juice < mile ){
			printf("Case %d: Juice %d\n", c, juice);
		}else if( juice == mile ){
			printf("Case %d: Mile Juice %d\n", c, juice);
		}

	}

	return 0;
}