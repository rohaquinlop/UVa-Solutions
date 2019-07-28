/*
*
* Problema UVA 352 - The Seasonal War
*
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

char graph[26][26];

int dx[] = {-1, 0, 1, -1 , 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void bfs(vector< vector<int> >& visited, int tam, int r, int c){
	if( r >= tam || c >= tam || visited[r][c] == 1 ){
		return;
	}
	visited[r][c] = 1;
	for(int i = 0; i < 8; i++)
		if( graph[r+dy[i]][c+dx[i]] == '1' )
			bfs(visited, tam, r+dy[i], c+dx[i]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i, j, count, c = 0;

	while( cin >> n ){
		c++;
		count = 0;
		vector< vector<int> >visited(n, vector<int>(n, -1));

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				cin >> graph[i][j];

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if( graph[i][j] == '1' && visited[i][j] == -1 ){
					bfs(visited, n, i, j);
					count++;
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", c, count);
	}


	return 0;
}