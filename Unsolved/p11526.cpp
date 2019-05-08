/*
*
* Problema UVA 11526 - H(n)
*
*/

#include <iostream>

using namespace std;

long long H(int n){
    long long res = 0;
    int i;

    for(i = 1; i <= n; i++){
        res = (res + n/i);
    }
    return res;
}

int main(){
    int cases, input;

    scanf("%d\n", &cases);

    while(cases--){
        scanf("%d\n", &input);
        cout << H(input) << endl;
    }

    return 0;
}