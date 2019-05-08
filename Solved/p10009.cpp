/*
*
* Problema UVA 10009 - All Roads Lead Where?
*
*/
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases, roads, queries;
	int i, j, tam, c=0;

	string a, b, start, end, search, aux;

	scanf("%d\n", &cases);

	while(cases--){
		c++;
		if( c > 1){
			printf("\n");
		}
		map<string, vector<string> > graph;
		map<string, bool> visited;
		map<string, bool>::iterator it;

		vector< pair<string, string> > q;
		map <string, string> route;

		scanf("%d %d\n", &roads, &queries);

		for(i = 0; i < roads; i++){
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
			visited[a] = false;
			visited[b] = false;
		}

		for(i = 0; i < queries; i++){
			for(it = visited.begin(); it != visited.end(); it++){
				it->second = false;
			}

			cin >> start >> end;

			queue<string> cola;
			cola.push(start);
			visited[start] = true;

			while( !cola.empty() ){
				search = cola.front();
				cola.pop();

				if( search == end ){
					break;
				}else{
					tam = graph[search].size();

					for(j = 0; j < tam; j++){
						aux = graph[search][j];
						if( !visited[aux] ){
							cola.push(aux);
							visited[aux] = true;
							route[aux] = search;
						}
					}
				}
			}
			
			vector<string> answer;
			pair<string, string> showing;
			while(end != start){
				answer.push_back( end );
				end = route[end];
			}
			cout << start[0];
			for(j = answer.size()-1; j >= 0; j--){
				cout << answer[j][0];
			}
			printf("\n");
			
			route.clear();

		}

	}


	return 0;
}
