/*
*
* Problema UVA 11942 - Lumberjack Sequencing
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, groups[10], i, title, asc, desc;

	scanf("%d", &cases);
	title = 0;

	while(cases--){
		asc = 0;
		desc = 0;

		for(i = 0; i < 10; i++){
			scanf("%d", &groups[i]);
		}

		for(i = 0; i < 9; i++){
			if( groups[i] < groups[i+1] ){
				asc++;
			}else if( groups[i] > groups[i+1] ){
				desc++;
			}
		}

		if(title == 0){
			printf("Lumberjacks:\n");
			title++;
		}
		if(asc == 9 || desc == 9){
			printf("Ordered\n");
		}else{
			printf("Unordered\n");
		}

	}

	return 0;
}