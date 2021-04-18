/*
*
* Problema UVA 10344 - 23 Out of 5
*
*/

#include <bits/stdc++.h>

using namespace std;

bool found;

void backTrack(int* nums, int i, int accum){
	if( found )
		return;
	if( i == 5 ){
		if( accum == 23 )
			found = true;
		return;
	}
	backTrack(nums, i+1, accum+nums[i]);
	backTrack(nums, i+1, accum-nums[i]);
	backTrack(nums, i+1, accum*nums[i]);
}

int main(){
	int nums[5];

	while( scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]) == 5 ){
		if( nums[0] ==  nums[1] && nums[1] == nums[2] && nums[2] == nums[3] &&
		nums[3] == nums[4] && nums[4] == 0 )
			break;
		else{
			sort(nums, nums+5);
			found = false;
			backTrack(nums, 1, nums[0]);
			while( next_permutation(nums, nums+5) ){
				if( found ){
					break;
				}
				backTrack(nums, 1, nums[0]);
			}
			if( found )
				printf("Possible\n");
			else
				printf("Impossible\n");
		}
	}


	return 0;
}