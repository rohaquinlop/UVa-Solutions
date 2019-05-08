/*
*
* Problema UVA 12503 - Robot Instructions
*
*/

#include <stdio.h>
#include <string.h>

int main(){
	int cases, n, pos, cont, as;
	char line[100];
	char movements[100][100];
	scanf("%d", &cases);

	while(cases--){
		scanf("%d", &n);
		pos = 0;
		cont = 0;

		while(n--){
			scanf("%s", line);
			if( !strcmp(line, "LEFT") ){
				pos--;
				movements[cont] = line;
			}else if( !strcmp(line, "RIGHT") ){
				pos++;
				movements[cont] = line;
			}else if( !strcmp(line, "SAME") ){
				scanf("%s", line);
				scanf("%d", &as);

				line = movements[as-1];
				if( !strcmp(line, "LEFT") ){
					pos--;
					movements[cont] = line;
				}else if( !strcmp(line, "RIGHT") ){
					pos++;
					movements[cont] = line;
				}
			}
			cont++;
		}
	}


	return 0;
}