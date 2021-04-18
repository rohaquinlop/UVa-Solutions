/*
*
* Problema UVa 10004 - Bicoloring
*
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, l, i, j, k, aux, node, tam;
	bool coloreable;

	while( scanf("%d", &n) == 1 ){
		if( n == 0 ) break;
		coloreable = true;
		map<int, vector<int> > graph;
		vector<int> visited(n, 0);
		vector<int> color(n, -1);
		scanf("%d", &l);
		for(i = 0; i < l; i++){
			scanf("%d %d", &j, &k);
			graph[j].push_back(k);
			graph[k].push_back(j);
		}

		queue<int> cola;
		cola.push(0);
		color[0] = 0;
		visited[0] = 1;

		while( !cola.empty() ){
			if (!coloreable) break;
			node = cola.front(); cola.pop();

			tam = graph[node].size();
			for(i = 0; i < tam; i++){
				aux = graph[node][i];
				if( color[aux] == color[node] ){
					coloreable = false;
					break;
				}
				if(!visited[aux]){
					visited[aux] = 1;
					cola.push(aux);
					color[aux] = !color[node];
				}
			}
		}

		if( coloreable ) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}


	return 0;
}