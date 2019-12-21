/*
*
* Problema UVa 10327 - Flip Sort
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, aux, count, i;

	while(cin >> n){
		vector<int> nums;
		count = 0;
		for(i = 0; i < n; i++){
			cin >> aux;
			nums.push_back(aux);
		}

		i = 0, count = 0;
		while( i < n-1){
			if( nums[i] > nums[i+1] ){
				aux = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = aux;
				count++;
				i = 0;
			}
			else{
				i++;
			}
		}

		printf("Minimum exchange operations : %d\n", count);
	}
}