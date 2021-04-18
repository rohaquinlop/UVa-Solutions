/*

Problema UVA 1172 | Relational Operator

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases;
	long int number1, number2;

	scanf("%d", &cases);

	while(cases--){
		scanf("%li %li", &number1, &number2);
		if(number1 > number2)
			printf("%s\n", ">");
		else if(number1 < number2)
			printf("%s\n", "<");
		else
			printf("%s\n", "=");
	}


	return 0;
}