/*
*
* Problema UVA 10783 | Odd sum
*
*/
#include <stdio.h>

int main(){
	int cases, countCase;
	int a, b, sum, i;

	while( scanf("%d", &cases) == 1 ){
		countCase = 1;
		while(cases){
			sum = 0;
			scanf("%d %d", &a, &b);

			for(i = a; i <= b; i++){
				if(i % 2 != 0){
					sum += i;
				}
			}

			printf("Case %d: %d\n", countCase, sum);


			countCase++;
			cases--;
		}
	}


	return 0;
}
