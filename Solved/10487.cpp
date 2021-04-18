/*
*
* Problema UVA 10487 - Closest Sums
*
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	int i, j, val, c = 0, pos, diff;

	while( scanf("%d", &n) == 1 ){
		if(n == 0){
			break;
		}else{
			c++;
			vector<int> nums;
			vector<int> sums;

			for(i = 0; i < n; i++){
				scanf("%d", &val);
				nums.push_back(val);
			}

			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					if( nums[i] != nums[j] ){
						sums.push_back( nums[i]+nums[j] );
					}
				}
			}

			sort(sums.begin(), sums.end());

			scanf("%d", &m);
			printf("Case %d:\n", c);

			for(i = 0; i < m; i++){
				scanf("%d", &val);
				diff = 2147483647;
				pos = 0;
				for(j = 0; j < sums.size(); j++){
					if( abs(val-sums[j]) < diff ){
						pos = j;
						diff = abs(val-sums[j]);
					}
				}
				printf("Closest sum to %d is %d.\n", val, sums[pos]);
			}

		}
	}


	return 0;
}
