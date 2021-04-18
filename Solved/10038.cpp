/*
*
* Problema UVA 10038 - Jolly Jumpers
*
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, i;
	vector<int> comp;
	bool jolly;

	for(i = 0; i < 3000; i++){
		comp.push_back(i+1);
	}

	while( scanf("%d", &n) == 1 ){
		if( n == 1 ){
			scanf("%d", &n);
			printf("Jolly\n");
		}else{
			jolly = true;
			int nums[n];
			int secc[n-1];

			for(i = 0; i < n; i++){
				scanf("%d", &nums[i]);
			}

			for(i = 1; i < n; i++){
				secc[i-1] = abs(nums[i-1] - nums[i]);
			}

			sort(secc, secc + n-1);

			for(i = 0; i < n-1; i++){
				if( secc[i] != comp[i] ){
					jolly = false;
				}
			}

			if( jolly ){
				printf("Jolly\n");
			}else{
				printf("Not jolly\n");
			}

		}
	}


	return 0;
}