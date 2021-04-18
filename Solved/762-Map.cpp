/*
*
* Problema UVA 762 - We Ship Cheap
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string p1, p2, start, end, search, aux;
	int cases, i, c=0;

	while( scanf("%d", &cases) == 1 ){
		c++;
		map<string, vector<string> > adjList;
		map<string, vector<string> >::iterator it;
		map<string, bool> visited;

		map<string, string> answer;
		queue<string> cola;
		bool connection = false;

		for(i = 0; i < cases; i++){
			cin >> p1;
			cin >> p2;
			adjList[p1].push_back(p2);
			adjList[p2].push_back(p1);
			visited[p1] = false;
			visited[p2] = false;
		}

		cin >> start;
		cin >> end;

		/* BFS */
		cola.push(start);
		visited[start] = true;

		while( !cola.empty() ){
			search = cola.front();
			cola.pop();
			if( search == end ){
				connection = true;
				break;
			}else{
				int tam = adjList[search].size();

				for( i = 0; i < tam; i++){
					aux = adjList[search][i];
					if( !visited[aux] ){
						visited[aux] = true;
						cola.push(aux);
						answer[aux] = search;
					}
				}
			}
		}

		if(c > 1){
			printf("\n");
		}

		if( connection ){
			vector< pair<string, string> > ruta;
			while( 1 ){
				if( start == end ){
					break;
				}else{
					ruta.push_back( make_pair(answer[end], end) );
					end = answer[end];
				}
			}

			for(i = ruta.size()-1; i >= 0; i--){
				cout << ruta[i].first << " " << ruta[i].second << endl;
			}
		}else{
			cout << "No route" << endl;
		}

	}


	return 0;
}
