/*
*
* Problema UVA 11057 - Exact Sum
*
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
	vector<long int> pBooks;
	long int cant, i, j, aux;
	long int money, dif, val1, val2;

	while( cin >> cant ){
		dif = 1000001;

		for(i = 0; i < cant; i++){
			cin >> aux;
			pBooks.push_back(aux);
		}

		cin >> money;

		for(i = 0; i < cant-1; i++){
			for(j = i+1; j < cant; j++ ){
				if( (pBooks[i]+pBooks[j]) == money && abs(pBooks[i]-pBooks[j]) <= dif ){
					if( pBooks[i] > pBooks[j] ){
						val1 = pBooks[j];
						val2 = pBooks[i];
					}else{
						val1 = pBooks[i];
						val2 = pBooks[j];
					}
					dif = abs(pBooks[i]-pBooks[j]);
				}
			}
		}

		printf("Peter should buy books whose prices are %li and %li.\n\n", val1, val2);

		pBooks.clear();

	}

  return 0;
}
