/*
*
* Problema UVA 1237 - Expert Enough?
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int cases;
	int database;
	char names[10000][20];
	char name[20];
	int prices[10000][2];
	int querys[1000];
	int i, q, find, j, pos, c = 0;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &database);

		for(i = 0; i < database; i++){
			scanf("%s %d %d", names[i], &prices[i][0], &prices[i][1]);
		}

		scanf("%d", &q);

		for(i = 0; i < q; i++){
			scanf("%d", &querys[i]);
		}

		if(c > 0){
			printf("\n");
		}
		c++;

		for(i = 0; i < q; i++){
			find = 0;
			pos = 0;
			for(j = 0; j < database; j++){
				if( (querys[i] >= prices[j][0]) && (querys[i] <= prices[j][1]) ){
					find++;
					pos = j;
				}
			}
			if(find == 0 || find > 1){
				printf("UNDETERMINED\n");
			}else{
				printf("%s\n", names[pos]);
			}
		}

	}


	return 0;
}
