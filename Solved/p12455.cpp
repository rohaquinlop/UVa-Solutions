/*
*
* Problema UVA 12455 - Bars
*
*/

#include <bits/stdc++.h>

using namespace std;

bool combinations(vector<int>& vec, int& c, int& val ){
	int i, numC = pow(2, c), j, sum;
	string s;

	for(i = 1; i <= numC; i++){
		sum = 0;
		s = bitset<32>(i).to_string();
		for(j = 32; j >= 0; j--){
			if( s[32-j] == '1' && 31-(32-j) < c ){
				sum += vec[31-(32-j)];
			}
		}

		if(sum == val){
			return true;
		}
	}

	return false;
}

int main(){
	int cases, val, n, i, aux;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &val);
		scanf("%d", &n);

		vector<int> nums;

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			nums.push_back(aux);
		}

		if( combinations(nums, n, val) ){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}