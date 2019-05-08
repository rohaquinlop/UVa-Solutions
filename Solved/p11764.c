/*
*
* Problema UVA 11764 - Jumping Mario
*
*/

#include <stdio.h>
#include <stdio.h>

int main(){
	int cases, cWalls, walls[50], i, high, low, c = 0;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &cWalls);
		high = 0;
		low = 0;
		c++;

		for(i = 0; i < cWalls; i++){
			scanf("%d", &walls[i]);
		}

		for(i = 0; i < cWalls-1; i++){
			if(walls[i] < walls[i+1]){
				high++;
			}else if(walls[i] > walls[i+1]){
				low++;
			}
		}

		printf("Case %d: %d %d\n", c, high, low);
	}


	return 0;
}