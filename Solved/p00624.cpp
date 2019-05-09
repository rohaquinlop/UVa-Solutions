/*
 *
 * Problema UVa 624 - CD
 *
*/

#include <bits/stdc++.h>

using namespace std;

int diff, sum;
vector<int> sol;

void backtracking(vector<int>& vec, int i, int acum, int val, vector<int> comb){
    if( acum == val ){
        sol = comb;
        sum = acum;
    }
    if( i == vec.size() && acum < val && sum < acum ){
        sol = comb;
        sum = acum;
    }
    if( (val-acum) > diff ){
        diff = val-acum;
    }
    if( i < vec.size() ){
        backtracking(vec, i+1, acum, val, comb);
        comb.push_back(vec[i]);
        backtracking(vec, i+1, acum + vec[i], val, comb);
    }
}

int main(){
    int n, t, aux, acum;
    int i;
    vector<int>::iterator it;

    while( scanf("%d", &n) == 1  ){
        scanf("%d", &t);
        diff = (-1)*n;
        acum = 0;
        sum = 0;
        vector<int> nums;
        vector<int> comb;
        sol.clear();

        for(i = 0; i < t; i++){
            scanf("%d", &aux);
            nums.push_back(aux);
        }
        i = 0;
        backtracking(nums, i, acum, n, comb);
        for(it = sol.begin(); it != sol.end(); it++ ){
            printf("%d ", *it);
        }
        printf("sum:%d\n", sum);
    }


    return 0;
}
