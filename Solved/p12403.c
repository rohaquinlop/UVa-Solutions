/*
*
* Problema UVA 12403 - Save Setu
*
*/

#include <stdio.h>
#include <string.h>

int main(){
	int cases, count = 0, n;
	char line[6];

	scanf("%d", &cases);

	while(cases--){
		scanf("%s", line);
		if( !strcmp(line, "donate") ){
			scanf("%d", &n);
			count += n;
		}else if( !strcmp(line, "report") ){
			printf("%d\n", count);
		}

	}


	return 0;
}
