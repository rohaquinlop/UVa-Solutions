/*
*
* Problema UVA 11679 - Sub-prime
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int banks, debentures;
	int reserves[20], i, deudor, credito, deuda, band;

	while( scanf("%d %d", &banks, &debentures) == 2 ){
		if( banks == 0 && debentures == 0 ){
			break;
		}else{
			band = 0;
			for(i = 0; i < banks; i++){
				scanf("%d", &reserves[i]);
			}

			for(i = 0; i < debentures; i++){
				scanf("%d %d %d", &deudor, &credito, &deuda);
				reserves[deudor-1] -= deuda;
				reserves[credito-1] += deuda;
			}

			for(i = 0; i < banks; i++){
				if(reserves[i] < 0){
					band = 1;
				}
			}

			if(band == 0){
				printf("S\n");
			}else{
				printf("N\n");
			}
		}
	}


	return 0;
}