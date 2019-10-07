/*
*
* Problema UVa 10127 - Ones
*
*/
#include<iostream>

using namespace std;

int main(){
    int n;
    int x, val;
    bool found;

    while( scanf("%d", &x) == 1 ){
        found = false;
        n = 1;
        val = 0;

        while( !found ){
            val++;
            if( n%x == 0 ) found = !found;
            else n = (n*10)%x+1%x;
        }

        printf("%d\n", val);
    }
    return 0;
}
