/*
*
* Problema UVA 10611 - The Playboy Chimp
*
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	vector<long int> ladys;
	long int n, q, i, aux, query, j, smaller, taller;
	long int found1, found2;

	scanf("%li", &n);

	for(i = 0; i < n; i++){
		scanf("%li", &aux);
		ladys.push_back(aux);
	}

	scanf("%li", &q);

	for(i = 0; i < q; i++){
		smaller = 0;
		taller = 2147483647;
		found1 = 0;
		found2 = 0;
		scanf("%li", &query);

		for(j = 0; j < ladys.size(); j++){
			if( (ladys[j] < query) && (ladys[j] > smaller) ){
				smaller = ladys[j];
				found1++;
			}
			if( (ladys[j] > query) && (ladys[j] < taller) ){
				taller = ladys[j];
				found2++;
			}
		}

		if( found1 && found2 ){
			printf("%li %li\n", smaller, taller);
		}else if( found1 > 0 && found2 == 0 ){
			printf("%li X\n", smaller);
		}else if( found1 == 0 && found2 > 0 ){
			printf("X %li\n", taller);
		}else{
			printf("X X\n");
		}
	}


  return 0;
}
