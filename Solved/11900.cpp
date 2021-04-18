/*
*
* Problema UVA 11900 - Boiled Eggs
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases, n, p, q, i, weight, eggs, c = 0;

	scanf("%d", &cases);

	while(cases--){
		c++;
		weight = 0, eggs = 0;
		scanf("%d %d %d", &n, &p, &q);
		int nums[n];
		for(i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		sort(nums, nums+n);

		for(i = 0; i < n; i++){
			if( weight+nums[i] <= q && eggs+1 <= p ){
				weight += nums[i];
				eggs++;
			}
		}

		printf("Case %d: %d\n", c, eggs);
	}

	return 0;
}