/*
*
* Problema UVA 11876 - N + NOD (N)
*
*/

#include <stdio.h>
#include <math.h>

int nod(int n){
	/* o(n) =  sum | n/d (d)
	for(d = 1; d <= n; d++)*/
}

int main(){
	int cases, a, b, i, sec, c = 0;

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		scanf("%d %d\n", &a, &b);

		i = a;
		sec = 0;

		while(i <= b){
			i += nod(i);
			sec++;
		}

		printf("case %d: %d\n", c, sec);
	}


	return 0;
}