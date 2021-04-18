/*
 *
 * Problema UVa 10370 - Above Average
 *
*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cases, n, i, aux, sum, count;
    double cant;
    scanf("%d\n", &cases);

    while(cases--){
        sum = 0, cant = 0, count = 0;
        vector<int> nums;
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d", &aux);
            sum += aux;
            nums.push_back(aux);
        }

        cant = sum / n;

        for(i = 0; i < n; i++){
            if( nums[i] > cant )
                count++;
        }

        printf("%.3lf%%\n", count*100.0/n);

    }

    return 0;
}
