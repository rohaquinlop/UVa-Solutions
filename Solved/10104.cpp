/*
 *
 * Problema UVa 10104 - Euclid Problem
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int x = 0, y = 0, d = 0;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

void extendedEuclid(int a, int b){
    if (b == 0){
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a%b);
    int x1 = y;
    int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int main(){
    int a, b;

    while( scanf("%d %d", &a, &b) == 2  ){
        d = gcd(a, b);
        extendedEuclid(a, b);
        printf("%d %d %d\n", x, y, d);
    }


    return 0;
}
