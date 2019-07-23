/*
*
* Problema UVA 260 - Il Gioco dell’X
*
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

class Pos{
public:
	int x;
	int y;
public:
	Pos(int _x, int _y){
		x = _x;
		y = _y;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i, j, c = 0;
	char start;
	bool winB, winW;

	while( cin >> n ){
		c++;
		if( n == 0)
			break;
		else{
			winB = false;
			winW = false;
			char array[n][n];

			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					cin >> array[i][j];

			//Black Moves
			for(i = 0; i < n; i++){
				if( array[0][i] == 'b' && !winB ){
					queue<Pos> cola;
					cola.push(Pos(i, 0));
					vector< vector<int> > visited(n, vector<int>(n, -1));
					visited[0][i] = 1;

					while( !cola.empty() ){
						Pos a = cola.front();
						cola.pop();
						if(a.y == n-1){
							winB = true;
							break;
						}
						for(j = 0; j < 6; j++){
							if( (a.y+dy[j] >= 0 && a.y+dy[j] < n) &&
								(a.x+dx[j] >= 0 && a.x+dx[j] < n) &&
								array[a.y+dy[j]][a.x+dx[j]] == 'b' &&
								visited[a.y+dy[j]][a.x+dx[j]] == -1){
								visited[a.y+dy[j]][a.x+dx[j]] = 1;
								cola.push( Pos(a.x+dx[j], a.y+dy[j]) );
							}
						}
					}
				}
			}

			//white moves
			for(i = 0; i < n; i++){
				if( array[i][0] == 'w' && !winW ){
					queue<Pos> cola;
					cola.push(Pos(0, i));
					vector< vector<int> > visited(n, vector<int>(n, -1));
					visited[i][0] = 1;

					while( !cola.empty() ){
						Pos a = cola.front();
						cola.pop();
						if(a.x == n-1){
							winW = true;
							break;
						}
						for(j = 0; j < 6; j++){
							if( (a.y+dy[j] >= 0 && a.y+dy[j] < n) &&
								(a.x+dx[j] >= 0 && a.x+dx[j] < n) &&
								array[a.y+dy[j]][a.x+dx[j]] == 'w' &&
								visited[a.y+dy[j]][a.x+dx[j]] == -1){
								visited[a.y+dy[j]][a.x+dx[j]] = 1;
								cola.push( Pos(a.x+dx[j], a.y+dy[j]) );
							}
						}
					}
				}
			}

			if( winB )
				printf("%d B\n", c);
			if( winW )
				printf("%d W\n", c);

		}
	}

	return 0;
}