/*
*
* Problema UVA 10071 - Back to High School Physics
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int vel, time;
	long int result;

	while( scanf("%d %d", &vel, &time) == 2 ){
		result = (vel * (time * 2) );
		printf("%li\n", result);
	}

	return 0;
}