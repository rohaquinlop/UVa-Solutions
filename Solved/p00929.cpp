/*
*
* Problema UVA 929 - Number Maze
*
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Edge{
public:
	int x, y;
	int cost;

	Edge(int a, int b, int c){
		x = a, y = b, cost = c;
	}

	bool operator >(const Edge& e) const{
		return cost > e.cost;
	}

};

int main(){
	int cases, k;
	int n, m, i, j;
	int x, y;

	cin >> cases;

	while(cases--){
		cin >> n >> m;

		vector< vector<int> > maze(n, vector<int>(m));
		vector< vector<int> > cost(n, vector<int>(m, -1));
		priority_queue< Edge, vector<Edge>, greater<Edge> > pq;

		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				cin >> maze[i][j];
			}
		}

		Edge e(0, 0, maze[0][0]);
		pq.push(e);
		cost[0][0] = e.cost;

		while( !pq.empty() ){
			Edge aux = pq.top();
			pq.pop();

			for(i = 0; i < 4; i++){
				x = aux.x + dx[i];
				y = aux.y + dy[i];

				if( x < 0 || x >= n || y < 0 || y >= m){
					continue;
				}

				if( cost[x][y] == -1 || cost[aux.x][aux.y] + maze[x][y] < cost[x][y] ){
					cost[x][y] = cost[aux.x][aux.y] + maze[x][y];
					e.x = x;
					e.y = y;

					e.cost = cost[x][y];
					pq.push(e);
				}
			}
		}
		printf("%d\n", cost[n-1][m-1]);
	}

	return 0;
}
