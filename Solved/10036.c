/*
*
* Problema UVA 10036 - Divisibility
*
*/
#include <stdio.h>
#include <string.h>

int isDiv;
int memo[101][10001];

int module(int i, int k){
	if( i%k < 0 )
		return (-1)*(i%k);
	else
		return i%k;
}

void backTrack(int* nums, int accum, int n, int i, int k, int mod){
	if( isDiv )
		return;
	if( i >= n ){
		if( mod == 0 )
			isDiv = 1;
		return;
	}

	if( memo[mod][i] == -1 ){
		backTrack(nums, accum+nums[i], n, i+1, k, module(accum + nums[i], k));
		backTrack(nums, accum-nums[i], n, i+1, k, module(accum - nums[i], k));
		memo[mod][i] = 1;
	}
	return;
}

int main(){
	int cases, n, k, i, j;

	scanf("%d", &cases);

	while(cases--){
		isDiv = 0;
		scanf("%d %d", &n, &k);
		int nums[n];

		for(i = 0; i < n; i++){
			scanf("%d", &nums[i]);
		}

		memset(memo, -1, sizeof(memo));
		backTrack(nums, nums[0], n, 1, k, module(nums[0], k));

		if(isDiv)
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}


	return 0;
}