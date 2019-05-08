/*
*
* Problema UVA 11831 - Sticker Collector Robots
*
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int rows, col, instr;
	string looking, aux, aux1;
	int posX, posY, i, j, k;
	char line;
	int cant;

	while( scanf("%d %d %d", &rows, &col, &instr) == 3 ){
		if( rows == 0 && col == 0 && instr == 0 ){
			break;
		}else{
			int arena[rows][col];
			/* Rellenando la matriz */
			for(i = 0; i < rows; i++){
				cin >> aux;
				for(j = 0; j < col; j++){
					aux1 = aux[j];
					if( aux1 == "." )
						arena[i][j] = 0;
					else if( aux1 == "*" )
						arena[i][j] = 1;
					else if( aux1 == "#" )
						arena[i][j] = 2;
					else{
						arena[i][j] = 0;
						posX = j;
						posY = i;
						if(aux1 == "N")
							looking = "N";
						else if( aux1 == "S" )
							looking = "S";
						else if( aux1 == "L" )
							looking = "E";
						else if( aux1 == "O" )
							looking = "W";
					}
				}
			}
			/* Tomando las instrucciones */
			vector<string> instructions;
			cin >> aux;
			for(i = 0; i < instr; i++){
				aux1 = aux[i];
				instructions.push_back(aux1);
			}
			/* Recorriendo el arreglo */
			cant = 0;

			for(k = 0; k < instructions.size(); k++){
				if( instructions[k] == "D" ){
					if( looking == "N" )
						looking = "E";
					else if( looking == "E" )
						looking = "S";
					else if( looking == "S" )
						looking = "W";
					else if( looking == "W" )
						looking = "N";
				}
				else if( instructions[k] == "E" ){
					if( looking == "N" )
						looking = "W";
					else if( looking == "W" )
						looking = "S";
					else if( looking == "S" )
						looking = "E";
					else if( looking == "E" )
						looking = "N";
				}
				else if( instructions[k] == "F" ){
					if( looking == "N" ){
						if( posY > 0 && arena[posY-1][posX] != 2 ){
							posY--;
							if( arena[posY][posX] == 1 ){
								cant++;
								arena[posY][posX] = 0;
							}
						}
					}
					if( looking == "E" ){
						if( posX < col-1 && arena[posY][posX+1] != 2  ){
							posX++;
							if( arena[posY][posX] == 1 ){
								cant++;
								arena[posY][posX] = 0;
							}
						}
					}
					if( looking == "S" ){
						if( posY < rows-1 && arena[posY+1][posX] != 2 ){
							posY++;
							if( arena[posY][posX] == 1 ){
								cant++;
								arena[posY][posX] = 0;
							}
						}
					}
					if( looking == "W" ){
						if( posX > 0 && arena[posY][posX-1] != 2 ){
							posX--;
							if( arena[posY][posX] == 1 ){
								cant++;
								arena[posY][posX] = 0;
							}
						}
					}
				}
			}
			printf("%d\n", cant);
		}
	}

  return 0;
}
