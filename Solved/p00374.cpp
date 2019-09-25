/*
*
* Problema UVa 374 - Big Mod
*
*/

#include <bits/stdc++.h>

using namespace std;

long long int expBin(long long int b, long long int p, long long int m){
	if(p == 0) return 1;
	if( p%2 == 0 ){
		long long int val = expBin(b, p/2, m)%m;
		return (val*val)%m;
	}
	return (b*expBin(b, p-1, m))%m;
}

int main(){
	long long int b, p, m;
	while( scanf("%lli\n%lli\n%lli", &b, &p, &m) == 3 ){
		printf("%lli\n", expBin(b,p,m));
	}


	return 0;
}