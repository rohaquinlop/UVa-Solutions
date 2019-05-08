/*
*
* Problema UVA 10324 - Zeros and Ones
*
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string line, aux;
	int i, j, k, mn, mx, cases, c = 0, band;

	while( getline(cin, line) ){
		c++;

		scanf("%d\n", &cases);

		printf("Case %d:\n", c);
		while(cases--){
			scanf("%d %d\n", &j, &k);
			mn = min(j, k);
			mx = max(j, k);
			band = 0;
			for( i = mn; i < mx; i++){
				if(line[i] != line[i+1]){
					band = 1;
				}
			}
			if( mn == mx ){
				band = 0;
			}
			if( band == 0 ){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}

	return 0;
}