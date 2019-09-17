/*
*
* Problema UVA 10346 - Peter’s Smokes
*
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;

	while( scanf("%d %d", &n, &k) == 2 ){
        printf("%d\n", n+(n-1)/(k-1));
	}


	return 0;
}
