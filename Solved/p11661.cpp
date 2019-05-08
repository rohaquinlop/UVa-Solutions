/*
*
* Problema UVA 11661 - Burger Time?
*
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int l, i, j, k, distance;
	int flag1, flag2;

	string line, aux1, aux2;

	while( scanf("%d", &l) == 1 ){
		if(l == 0){
			break;
		}else{
			cin >> line;
			flag1 = 0;
			flag2 = 0;

			distance = 2000000;

			for(i = 0; i < l; i++){
				aux1 = line[i];
				if( aux1 == "Z" ){
					distance = 0;
				}else if( aux1 == "R" ){
					j =  i;
					flag1 = 1;
				}else if( aux1 == "D" ){
					k = i;
					flag2 = 1;
				}

				if( flag1 && flag2 ){
					if(abs(j-k) < distance)
						distance = abs(j-k);
				}
			}

			printf("%d\n", distance);
		}
	}


	return 0;
}