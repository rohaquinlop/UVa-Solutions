/*
*
* Problema UVA 10664 - Luggage
*
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int nums[21];
int memo[200][20];
int maxDiff;
bool isPosible;

void backTrack(int* nums, int i, int& n, int left, int right){
	if( isPosible )
		return;
	if(i >= n){
		if( abs(left-right) == 0 )
			isPosible = true;
		return;
	}

	if( memo[abs(left-right)][i] == -1 ){
		backTrack(nums, i+1, n, left, right+nums[i]);
		backTrack(nums, i+1, n, left+nums[i], right);
		memo[abs(left-right)][i] = 1;
	}
}

int main(){
	int cases, n, i;
	string line;

	scanf("%d\n", &cases);

	while(cases--){
		getline(cin, line);
		stringstream ss(line);
		i = 0;
		while( ss.good() ){
			ss >> nums[i];
			i++;
		}

		isPosible = false;
		maxDiff = 201;

		memset(memo, -1, sizeof(memo));

		backTrack(nums, 0, i, 0, 0);

		if( isPosible )
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}