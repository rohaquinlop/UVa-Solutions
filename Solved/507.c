/*
*
* Problema UVa 507 - Jill Rides Again
*
*/

#include <stdio.h>

int main(){
	int i, j, begin, end, max, act, bTemp, eTemp;
	int cases, c = 0, tam;
	int nums[20000];

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		scanf("%d\n", &tam);
		max = 0, act = -1, begin = 0, end = 0, tam--, bTemp = 0, eTemp = 0;

		for(i = 0; i < tam; i++)
			scanf("%d\n", &nums[i]);

		for(i = 0; i < tam; i++){
			if( act < 0 && nums[i] > 0 ){
				act = nums[i];
				begin = i+1;
				end = i+2;
			}else{
				act += nums[i];
				if( act >= 0)
					end++;
			}
			if( act > max ){
				max = act;
				eTemp = end;
				bTemp = begin;
			}
			if( act == max && (eTemp-bTemp) < (end-begin) ){
				eTemp = end;
				bTemp = begin;
			}
		}

		if( max )
			printf("The nicest part of route %d is between stops %d and %d\n", c, bTemp, eTemp);
		else
			printf("Route %d has no nice parts\n", c);

	}



	return 0;
}