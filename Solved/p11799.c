/*
*
* Problema UVA 11799 - Horror Dash
*
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, students;
	int aux, i, c, speed;

	scanf("%d", &cases);
	c = 0;

	while(cases--){
		c++;
		speed = 0;
		scanf("%d", &students);

		for(i = 0; i < students; i++){
			scanf(" %d", &aux);
			if(aux > speed)
				speed = aux;
		}
		printf("Case %d: %d\n", c, speed);
	}

	return 0;
}
