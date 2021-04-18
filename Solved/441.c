/*
*
* Problema UVA 441 Lotto
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int arrray[13];
	int k, c = 0;
	int i, j, l, m, n, p;

	while( scanf("%d", &k) == 1 ){
		if(k == 0){
			break;
		}else{
			c++;

			if(c > 1){
				printf("\n");
			}

			for(i = 0; i < k; i++){
				scanf("%d", &arrray[i]);
			}

			for(i = 0; i < k-5; i++){
				for(j = i+1; j < k-4; j++){
					for(l = j+1; l < k-3; l++){
						for(m = l+1; m < k-2; m++){
							for(n = m+1; n < k-1; n++){
								for(p = n+1; p < k; p++){
									printf("%d %d %d %d %d %d\n",
										arrray[i], arrray[j], arrray[l], arrray[m], arrray[n], arrray[p]);
								}
							}
						}
					}
				}
			}

		}
	}


	return 0;
}