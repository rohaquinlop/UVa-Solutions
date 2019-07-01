/*
*
* Problema UVa 10684 - The jackpot
*
*/

#include <stdio.h>

int main(){
	int nums[10000];
	int i, n, bet, high;

	while( scanf("%d", &n) == 1 ){
		if( n == 0 )
			break;
		else{
			bet = 0;
			high = 0;

			for(i = 0; i < n; i++)
				scanf("%d", &nums[i]);

			for(i = 0; i < n; i++){
				if( bet <= 0 && nums[i] > 0 )
					bet = nums[i];
				else{
					bet += nums[i];
				}
				if( bet > high )
					high = bet;
			}

			if(high)
				printf("The maximum winning streak is %d.\n", high);
			else
				printf("Losing streak.\n");

		}
	}


	return 0;
}