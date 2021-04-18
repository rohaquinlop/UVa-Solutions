/*
*
* Problema UVa 10125 - Sumsets
*
*/
#include <bits/stdc++.h>

using namespace std;

bool cmp(int& a, int& b){
	return a > b;
}

int main(){
	int n, i, j, k, l, accum;
	bool found, isCero;

	while( scanf("%d", &n) == 1 ){
		if( n == 0 ) break;
		int nums[n];
		isCero = false;
		for(i = 0; i < n; i++){
			scanf("%d", &nums[i]);
			if( nums[i] == 0 ) isCero = true;
		}

		sort(nums, nums+n, cmp);
		accum = -1;
		found = false;

		for(i = 0; i < n && !found; i++){
			for(j = 0; j < n && !found; j++){
				for(k = j+1; k < n && !found; k++){
					for(l = k+1; l < n && !found; l++){
						if( nums[j] != nums[k] && nums[j] != nums[l] && nums[k] != nums[l] && 
							nums[j] != nums[i] && nums[i] != nums[l] && nums[k] != nums[i] && 
							nums[j]+nums[k]+nums[l] == nums[i]){
							accum = nums[i];
							found = true;
						}
					}
				}
			}
		}


		for(i = n-1; i >= 0 && !found; i--){
			for(j = n-1; j >= 0 && !found; j--){
				for(k = j-1; k >= 0 && !found; k--){
					for(l = k-1; l >= 0 && !found; l--){
						if( nums[j] != nums[k] && nums[j] != nums[l] && nums[k] != nums[l] && 
							nums[j] != nums[i] && nums[i] != nums[l] && nums[k] != nums[i] && 
							nums[j]+nums[k]+nums[l] == nums[i]){
							accum = nums[i];
							found = true;
						}
					}
				}
			}
		}

		if( !found ) printf("no solution\n");
		else printf("%d\n", accum);
	}


	return 0;
}