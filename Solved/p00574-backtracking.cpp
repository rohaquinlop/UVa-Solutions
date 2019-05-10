/*
 *
 * Problema UVa 574 - Sum It Up
 *
*/
#include <bits/stdc++.h>

using namespace std;

int cSums = 0;
set< vector<int> > vals;

void backTracking(vector<int>& nums, int i, int sum, int val, vector<int> comb){
    if( sum == val ){
        cSums++;
        vals.insert(comb);
    }
    if( i == nums.size() ){
        return;
    }
    backTracking(nums, i+1, sum, val, comb);
    comb.push_back(nums[i]);
    backTracking(nums, i+1, sum + nums[i], val, comb);
}

int main(){
    int sum, n, i, aux, count;

    while( scanf("%d %d", &sum, &n) == 2  ){
        if( sum == 0 && n == 0  ){
            break;
        }
        cSums = 0;

        vector<int> nums;
        vector<int> comb;
        vals.clear();

        for(i = 0; i < n; i++){
            scanf("%d", &aux);
            nums.push_back(aux);
        }
        i = 0;
        count = 0;
        printf("Sums of %d:\n", sum);
        backTracking(nums, i, count, sum, comb);
        if( !cSums ){
            printf("NONE\n");
        }else{
            set< vector<int> >::iterator it;
            stack< vector<int> > sums;

            for(it = vals.begin(); it != vals.end(); it++){
                vector<int> vAux = *it;
                sums.push(vAux);
            }

            while( !sums.empty()  ){
                vector<int> vAux = sums.top();
                sums.pop();
                for( i = 0; i < vAux.size(); i++ ){
                    printf("%d", vAux[i]);
                    if( i < vAux.size()-1  ){
                        printf("+");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}
