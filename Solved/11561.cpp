/*
*
* Problema UVA 11561 - Getting Gold
*
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool itsaTrap(int& a, int& b, vector< vector <char> >& maze){
	int x, y;

	for(int i = 0; i < 4; i++){
		x = a+dx[i];
		y = b+dy[i];

		if( maze[y][x] == 'T' ){
			return true;
		}
	}
	return false;
}

int main(){
	char aux;
	int h, w, i, j, maxG, x, y;

	while( cin >> w >> h ){

		vector< vector<char> > maze(50);
		vector< vector<bool> > visited(50);

		for(i = 0; i < h; i++){
			for(j = 0; j < w; j++){
				cin >> aux;
				maze[i].push_back(aux);
				if( maze[i][j] == 'P' ){
					x = j;
					y = i;
				}
				visited[i].push_back(false);
			}
		}

		maxG = 0;
		stack< pair<int, int> > pila;
		pair<int, int> par(x, y);
		pila.push(par);
		visited[y][x] = true;

		while( !pila.empty() ){
			par = pila.top();
			pila.pop();

			if( maze[par.second][par.first] == 'G' ){
				maxG++;
			}

			if ( !itsaTrap( par.first, par.second, maze)){
				for(i = 0; i < 4; i++){
					x = par.first+dx[i];
					y = par.second+dy[i];

					if( !visited[y][x] && maze[y][x] != '#' ){
						pila.push( make_pair(x, y) );
						visited[y][x] = true;
					}

				}
			}

		}

		printf("%d\n", maxG);
	}

	return 0;
}