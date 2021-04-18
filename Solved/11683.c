/*
*
* Problema UVA 11683 - Laser Sculpture
*
*/

#include <stdio.h>

int main(){
	int a, c;
	int i, j, count;
	int array[10000];

	while( scanf("%d %d", &a, &c) == 2 ){
		/* Alto (a) y Ancho (c) */
		if( a == 0 && c == 0){
			break;
		}else{
			count = 0;
			j = a;

			for(i = 0; i < c; i++){
				scanf("%d", &array[i]);
			}

			for(i = c-1; i >= 0; i--){
				if( array[i] < j ){
					count += j - array[i];
				}
				j = array[i];
			}

			printf("%d\n", count);
		}
	}


  return 0;
}
