/*
 *
 * Problema UVa 12455 - Bars
 *
*/

#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void backTracking(vector<int>& nums, int i, int acum, int& val){
    if( acum == val ){
        ans = 1;
        return;
    }else if( acum > val || i == nums.size() ){
        return;
    }
    backTracking(nums, i+1, acum + nums[i], val);
    backTracking(nums, i+1, acum, val);
}

int main(){
    int cases, val, n, i, aux, sum;

    scanf("%d\n", &cases);

    while(cases--){
        scanf("%d\n%d\n", &val, &n);
        vector<int> nums;

        for(i = 0; i < n; i++){
            scanf("%d", &aux);
            nums.push_back(aux);
        }
        i = 0;
        sum = 0;
        ans = 0;
        backTracking(nums, i, sum, val);

        if( ans == 0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }

    return 0;
}
