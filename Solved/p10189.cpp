/*
*
* Problema UVA 10189 - Minesweeper
*
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int n, m, i, j, k, x, y, c = 0;
	char f;

	while( cin >> n >> m ){
		if(n == 0 && m == 0){
			break;
		}else{
			c++;
			int array[n][m];

			for(i = 0; i < n; i++){
				for(j = 0; j < m; j++){
					cin >> f;
					if( f == '*' ){
						array[i][j] = -1;
					}else{
						array[i][j] = 0;
					}
				}
			}

			for(i = 0; i < n; i++){
				for(j = 0; j < m; j++){
					if( array[i][j] == -1 ){
						for(k = 0; k < 8; k++){
							x = dx[k];
							y = dy[k];
							if( (i+x >= 0 && i+x < n) && (j+y >= 0 && j+y < m) && (array[i+x][j+y] != -1) ){
								array[i+x][j+y]++;
							}
						}
					}
				}
			}

			if(c > 1){
				printf("\n");
			}
			printf("Field #%d:\n", c);
			for(i = 0; i < n; i++){
				for(j = 0; j < m; j++){
					if(array[i][j] == -1){
						printf("*");
					}else{
						printf("%d", array[i][j]);
					}
				}
				printf("\n");
			}

		}
	}

	return 0;
}
