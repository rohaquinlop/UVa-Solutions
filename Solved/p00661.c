/*
*
* Problema UVA 661 - Blowing Fuses
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, c, devices[20], actions[20];
	int i, consumo, seq = 0, band, max, aux;

	while( scanf("%d %d %d", &n, &m, &c) == 3 ){
		if( n == 0 && m == 0 && c == 0 ){
			break;
		}else{
			seq++;
			band = 0;
			consumo = 0;
			max = 0;
			/* Consumo de cada dispositivo */
			for( i = 0; i < n; i++ ){
				scanf("%d", &devices[i]);
				actions[i] = 0;
			}

			for(i = 0; i < m; i++ ){
				scanf("%d", &aux);

				if( actions[aux-1] == 0 ){
					actions[aux-1] = 1;
					consumo += devices[aux-1];
				}else if( actions[aux-1] == 1 ){
					actions[aux-1] = 0;
					consumo -= devices[aux-1];
				}

				if(consumo > max && band == 0){
					max = consumo;
				}

				if( consumo > c ){
					band = 1;
				}
			}

			printf("Sequence %d\n", seq);

			if(band == 1){
				printf("Fuse was blown.\n");
			}else if( band == 0 ){
				printf("Fuse was not blown.\n");
				printf("Maximal power consumption was %d amperes.\n", max);
			}
			printf("\n");
		}
	}

	return 0;
}
