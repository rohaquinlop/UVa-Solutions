/*
*
* Problema UVA 11661 - Burger Time?
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	char line[2000000];
	int i, j, k, l, distance;
	int flag1, flag2;

	while( scanf("%d\n", &l) != EOF ){
		if( l == 0 ){
			break;
		}else{
			scanf("%s\n", line);

			distance = 2000000;

			flag1 = 0;
			flag2 = 0;

			for(i = 0; i < l; i++){
				if( line[i] == 'R' ){
					j = i;
					flag1 = 1;
				}
				if( line[i] == 'D' ){
					k = i;
					flag2 = 1;
				}
				if ( line[i] == 'Z' ){
					distance = 0;
				}
				if( flag1 && flag2 ){
					if( abs(k-j) < distance ){
						distance = abs(k-j);
					}
				}
			}

			printf("%d\n", distance);
		}
	}

	return 0;
}
