/*
*
* Problema UVA 12468 - Zapping
*
*/

#include <stdio.h>

int main(){
	int a, b, aux1, aux2;

	while( scanf("%d %d", &a, &b) != EOF ){
		if( a == -1 && b == -1){
			break;
		}else{
			aux1 = a-b;
			if(aux1 < 0){
				aux1 *= -1;
			}

			aux2 = 100-aux1;

			if(aux1 < aux2){
				printf("%d\n", aux1);
			}else{
				printf("%d\n", aux2);
			}

		}
	}

	return 0;
}