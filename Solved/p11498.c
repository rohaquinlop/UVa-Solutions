/*

Problema UVA 11498 | Division of Nlogonia

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases;
	int inputX, inputY;
	int divX, divY;

	while( scanf("%d", &cases) == 1){
		if(cases > 0){
			scanf("%d %d", &divX, &divY);
			while(cases){
				scanf("%d %d", &inputX, &inputY);

				if(inputX == divX || inputY == divY){
					printf("%s\n", "divisa");
				}else if(inputX > divX && inputY > divY){
					printf("%s\n", "NE");
				}else if(inputX < divX && inputY > divY){
					printf("%s\n", "NO");
				}else if(inputX < divX && inputY < divY){
					printf("%s\n", "SO");
				}else if(inputX > divX && inputY < divY){
					printf("%s\n", "SE");
				}

				cases--;
			}
		}else{
			break;
		}
	}


	return 0;
}