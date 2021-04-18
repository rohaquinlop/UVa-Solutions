/*
*
* Problema UVA 11727 - Relational Operators
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, actCase = 1;
	int a, b, c;

	scanf("%d", &cases);

	while(cases){
		scanf("%d %d %d", &a, &b, &c);

		if(a > b && a > c){
			if(b > c){
				printf("%s%d%s %d\n", "Case ", actCase, ":", b);
			}else{
				printf("%s%d%s %d\n", "Case ", actCase, ":", c);
			}
		}else{
			if(b > a && b > c){
				if(a > c){
					printf("%s%d%s %d\n", "Case ", actCase, ":", a);
				}
				else{
					printf("%s%d%s %d\n", "Case ", actCase, ":", c);
				}
			}else{
				if(c > a && c > b){
					if(a > b){
						printf("%s%d%s %d\n", "Case ", actCase, ":", a);
					}
					else{
						printf("%s%d%s %d\n", "Case ", actCase, ":", b);
					}
				}else{
					printf("%s%d%s %d\n", "Case ", actCase, ":", b);
				}
			}
		}


		cases--;
		actCase++;
	}


	return 0;
}