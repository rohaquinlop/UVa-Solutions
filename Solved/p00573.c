/*
*
* Problema UVA 573 - The Snail
*
*/

#include <stdio.h>

int main(){
	float h, u, d, f, initial;
	int day, band;

	while(1){
		scanf("%f %f %f %f\n", &h, &u, &d, &f);
		if(h == 0 && u == 0 && d == 0 && f == 0){
			break;
		}else{
			day = 0;
			band = 0;
			initial = 0;
			f = (u*f)/100;
			while( band == 0 ){
				day++;

				if(day > 1){
					u -= f;
					if(u >= 0){
						initial += u;
					}
				}else{
					initial += u;
				}

				if( initial > h ){
					band = 2;
					break;
				}

				initial -= d;

				if( initial < 0 ){
					band = 1;
					break;
				}


			}

			if( band == 1 ){
				printf("failure on day %d\n", day);
			}else if( band == 2){
				printf("success on day %d\n", day);
			}

		}
	}


	return 0;
}