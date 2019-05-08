/*
*
* Problema UVA 336 - A Node Too Far
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int nConnections;
	int i, c = 0;
	int a,b;
	int start, search, tam, aux, ttl, visits;

	while( cin >> nConnections ){
		if( nConnections == 0 ){
			break;
		}else{
			map<int, vector<int> > graph;
			map<int, bool> visited;
			map<int, bool>::iterator it;
			map<int, int> weights;
		
			for(i = 0; i < nConnections; i++){
				cin>>a>>b;
				graph[a].push_back(b);
				graph[b].push_back(a);
				visited[a] = false;
				visited[b] = false;
				weights[a] = -1;
				weights[b] = -1;
			}

			while( cin >> start >> ttl ){
				if( start == 0 && ttl == 0 ){
					break;
				}else{
					c++;
					for(it = visited.begin(); it != visited.end(); it++){
						it->second = false;
					}

					queue<int> cola;
					cola.push(start);
					visited[start] = true;
					weights[start] = ttl;

					while( !cola.empty() ){
						search = cola.front();
						cola.pop();

						if( weights[search] > 0 ){
							tam = graph[search].size();

							for(i = 0; i < tam; i++){
								aux = graph[search][i];
								if( !visited[aux] ){
									weights[aux] = weights[search]-1;
									visited[aux] = true;
									cola.push(aux);
								}
							}
						}else{
							break;
						}
					}

					visits = 0;

					for(it = visited.begin(); it != visited.end(); it++){
						if( it->second == false ){
							visits++;
						}
					}

					printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", c, visits,start, ttl );

				}

			}

		}

	}

	return 0;
}
