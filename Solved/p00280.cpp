/*
*
* Problema UVA 280 - Vertex
*
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int n, t, i, j, search, tam, aux;

	while( scanf("%d", &n) == 1 ){
		if(n == 0){
			break;
		}else{
			map<int, vector<int> > graph;
			map<int, bool> visited;
			map<int, bool>::iterator it;

			while( scanf("%d", &i) == 1 ){
				if( i == 0 ){
					break;
				}else{
					while( scanf("%d", &j) == 1 ){
						if(j == 0){
							break;
						}else{
							graph[i].push_back(j);
						}
					}
				}
			}

			scanf("%d", &t);
			for(i = 0; i < t; i++){
				queue<int> cola;

				for(j = 0; j < n; j++){
					visited[j+1] = false;
				}

				scanf("%d", &j);
				cola.push(j);

				while( !cola.empty() ){
					search = cola.front();
					cola.pop();

					tam = graph[search].size();

					for(j = 0; j < tam; j++){
						aux = graph[search][j];
						if( !visited[aux] ){
							cola.push(aux);
							visited[aux] = true;
						}
					}
				}
				vector<int> unvisted;
				for(it = visited.begin(); it != visited.end(); it++){
					if( !(it->second) ){
						aux = it->first;
						unvisted.push_back(aux);
					}
				}
				printf("%d", unvisted.size());
				for(j = 0; j < unvisted.size(); j++){
					printf(" %d", unvisted[j]);
				}
				printf("\n");

			}


		}
	}


	return 0;
}