/*
*
* Problema UVA 12250 - Language Detection
*
*/

#include <stdio.h>
#include <string.h>

int main(){
	char line[14];
	int c = 0;


	while( scanf("%s\n", line) != EOF ){
		if( line[0] == '#' ){
			break;
		}else{
			c++;
			if( !strcmp(line, "HELLO") ){
				printf("Case %d: ENGLISH\n", c);
			}else if( !strcmp(line, "HOLA") ){
				printf("Case %d: SPANISH\n", c);
			}else if( !strcmp(line, "HALLO") ){
				printf("Case %d: GERMAN\n", c);
			}else if( !strcmp(line, "BONJOUR") ){
				printf("Case %d: FRENCH\n", c);
			}else if( !strcmp(line, "CIAO") ){
				printf("Case %d: ITALIAN\n", c);
			}else if( !strcmp(line, "ZDRAVSTVUJTE") ){
				printf("Case %d: RUSSIAN\n", c);
			}else{
				printf("Case %d: UNKNOWN\n", c);
			}
		}
	}



	return 0;
}
