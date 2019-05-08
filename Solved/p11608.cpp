/*
*
* Problema UVA 11608 - No Problem!
*
*/

#include <iostream>
#include <cstdio>

int main(){
	int cases;
	int problems[13], i, j, c = 0;;
	int required[12], available;

	while( scanf("%d", &cases) == 1){
		if(cases < 0){
			break;
		}else{
			c++;
			problems[0] = cases;

			for(i = 0; i < 12; i++){
				scanf("%d", &problems[i+1]);
			}

			for(i = 0; i < 12; i++){
				scanf("%d", &required[i]);
			}

			printf("Case %d:\n", c);

			for(i = 0; i < 12; i++){
				available = 0;
				for(j = 0; j < i+1; j++){
					available += problems[j];
				}
				if( required[i] <= available ){
					printf("No problem! :D\n");
					problems[i] -= required[i];
				}else{
					printf("No problem. :(\n");
				}
			}

		}

	}


	return 0;
}
