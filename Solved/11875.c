/*
*
* Problema UVA 11875 - Brick Game
*
*/

#include <stdio.h>

int main(){
	int array[11];
	int cases;
	int sec, i, c = 0;

	scanf("%d", &cases);

	while(cases--){
		c++;
		scanf("%d", &sec);

		for(i = 0; i < sec; i++){
			scanf("%d", &array[i]);
		}

		printf("Case %d: %d\n", c,array[sec/2]);
	}


	return 0;
}