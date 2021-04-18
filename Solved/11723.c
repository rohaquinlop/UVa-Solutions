/*
*
* Problema UVA 11723 - Numbering Roads!
*
*/

#include <stdio.h>

int main(){
	int r, n, c = 0, i;
	int cSuff;

	while( scanf("%d %d", &r, &n) == 2 ){
		if( r == 0 && n == 0 ){
			break;
		}else{
			c++;
			cSuff = 0;

			if( n*27 < r ){
				printf("Case %d: impossible\n", c);
			}else{
				for(i = 0; i < 26; i++){
					if( n*(i+1) >= r ){
						break;
					}else{
						cSuff++;
					}
				}
				printf("Case %d: %d\n", c, cSuff);
			}
		}
	}

	return 0;
}