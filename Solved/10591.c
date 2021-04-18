/*
*
* Problema UVA 10591 - Happy Number
*
*/
#include <stdio.h>
#include <string.h>

int memo[729];

int happy(int n){
	int accum = 0;

	while(n){
		accum += (n%10)*(n%10);
		n /= 10;
	}

	return accum;
}

int main(){
	int isPossible;
	int cases, iNum, c = 0, nNum;
	int memo[729];

	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &iNum);
		memset(memo, -1, sizeof(memo));
		c++;
		nNum = iNum;
		nNum = happy(nNum);
		isPossible = 0;
		printf("Case #%d: %d is ", c, iNum);
		if( nNum == 1 ){
			printf("a Happy number.\n");
		}else{
			memo[nNum] = 1;
			while( !isPossible ){
				nNum = happy(nNum);
				if( memo[nNum] == 1 )
					break;
				else{
					if( nNum == 1 ){
						isPossible = 1;
						break;
					}else{
						memo[nNum] = 1;
					}
				}
			}

			if(isPossible)
				printf("a Happy number.\n");
			else
				printf("an Unhappy number.\n");
		}
	}

	return 0;
}