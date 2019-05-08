/*
*
* Problema UVA 10340 - All in All
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char string1[509000];
	char string2[509000];
	int i, j, sum;
	while( scanf("%s %s", string1, string2) == 2 ){
		sum = 0;
		j = 0;

		for(i = 0; i < strlen(string1); i++){
			for(j; j < strlen(string2); j++){
				if( string1[i] == string2[j] ){
					sum++;
					j++;
					break;
				}
			}
		}

		if( sum == strlen(string1) ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}


	return 0;
}
