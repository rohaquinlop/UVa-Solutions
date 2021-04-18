/*
*
* Problema UVA 10050 - Hartals
*
*/
#include <stdio.h>

int main(){
	int days[3651];
	int hartals[101];
	int cases, n, p;
	int sum;
	int i, j;

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		scanf("%d", &p);

		sum = 0;

		for(i = 0; i < p; i++){
			scanf("%d", &hartals[i]);
		}

		for(i = 0; i < n; i++){
			days[i] = 0;
		}

		for(i = 0; i < p; i++){
			for(j = hartals[i]-1; j < n; j += (hartals[i]) ){
				days[j] = 1;
			}
		}

		for(i = 0; i < n; i++){
			if( days[i] == 1 ){
				j = i+1;
				if( j%7 == 0 || j%7 == 6 ){
					continue;
				}else{
					sum++;
				}
			}
		}

		printf("%d\n", sum);



	}


	return 0;
}
