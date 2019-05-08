/*
*
* Problema UVA 11824 - A Minimum Land Price
*
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

bool compare(unsigned long int a, unsigned long int b){
	return a > b;
}

unsigned long long int potencia(unsigned long long int n, int x){
	unsigned long int res = n;

	for(int i = 0; i < x-1; i++){
		res *= n;
	}

	return 2*res;
}

using namespace std;

int main(){
	int cases, i;
	unsigned long long int n, value, aux;

	vector<unsigned long long int> vals;

	scanf("%d\n", &cases);

	while(cases--){
		while( scanf("%llu", &n) == 1 ){
			if(n == 0){
				sort(vals.begin(), vals.end(), compare);
				value = 0;

				for(i = 0; i < vals.size(); i++){
					aux = potencia(vals[i], i+1 );
					value += aux;
				}

				if( value > 5000000 ){
					printf("Too expensive\n");
				}else{
					printf("%lu\n", value);
				}
				vals.clear();
				break;
			}else{
				vals.push_back(n);
			}
		}
	}


	return 0;
}
