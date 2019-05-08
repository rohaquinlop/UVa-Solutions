/*
*
* Problema UVA 12015 - Google is Feeling Lucky
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases;
	char array[10][101];
	int nums[10];
	int i, higher, c=0;

	scanf("%d\n", &cases);

	while(cases--){

		higher = -1;
		c++;

		for(i = 0; i < 10; i++){
			scanf("%s %d\n", array[i], &nums[i]);
			if( nums[i] > higher ){
				higher = nums[i];
			}
		}
		printf("Case #%d:\n", c);

		for(i = 0; i < 10; i++){
			if( nums[i] == higher ){
				printf("%s\n", array[i]);
			}
		}

	}



	return 0;
}
