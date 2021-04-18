/*

Problema UVA 10055 | Hashmat the brave warrior

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	long long hash, opponent, result;

	while( scanf("%lli %lli", &hash, &opponent) == 2){
		if(hash > opponent){
			result = hash-opponent;
			printf("%lli\n", result );
		}else{
			result = opponent-hash;
			printf("%lli\n", result );
		}
	}

	return 0;
}