/*
*
* Problema UVA 562 - Dividing coins
*
*/
#include <math.h>
#include <stdio.h>
#include <string.h>

int maxDiff;
int memo[50000][101];

void backTrack(int* nums, int i, int n, int left, int right){
	if( i >= n || !maxDiff){
		if( abs(left-right) < maxDiff )
			maxDiff = abs(left-right);
		return;
	}

	if( memo[abs(left-right)][i] == -1 ){
		backTrack(nums, i+1, n, left+nums[i], right);
		backTrack(nums, i+1, n, left, right+nums[i]);
		memo[abs(left-right)][i] = 1;
	}
}

int main(){
	int cases, n, aux, i, acum;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		int nums[n];
		maxDiff = 500;
		memset(memo, -1, sizeof(memo));

		for(i = 0; i < n; i++)
			scanf("%d", &nums[i]);

		backTrack(nums, 0, n, 0, 0);

		printf("%d\n", maxDiff);
	}
	return 0;
}