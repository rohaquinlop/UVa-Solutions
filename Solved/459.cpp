/*
*
* Problema UVA 459 - Graph Connectivity
*
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cases, i, tam, count;
	string line;
	char a, b;

	cin >> cases;
	getline(cin, line);
	getline(cin, line);

	while(cases--){
		getline(cin, line);
		map<char, vector<char>> graph;
		map<char, vector<char>>::iterator it;
		map<char, bool> visited;
		count = 0;
		b = line[0];

		a = 'A';
		
		while(a <= b){
			graph[a].push_back(a);
			visited[a] = false;
			a++;
		}

		while( getline(cin, line) && line.size() > 0 ){
			a = line[0]; b = line[1];
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for(it = graph.begin(); it != graph.end(); it++){
			if( !visited[(it->first)] ){
				count++;
				visited[(it->first)] = true;
				queue<char> cola;
				cola.push( (it->first) );

				while( !cola.empty() ){
					a = cola.front(); cola.pop();
					tam = graph[a].size();

					for(i = 0; i < tam; i++){
						b = graph[a][i];
						if( !visited[b] ){
							cola.push(b);
							visited[b] = true;
						}
					}
				}
			}
		}

		printf("%d\n", count);
		if( cases >= 1 )
			printf("\n");
	}


	return 0;
}