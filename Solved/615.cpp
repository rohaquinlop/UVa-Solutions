/*
*
* Problema UVA 615 - Is It A Tree?
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int f, s, c = 0, inputs=0;
	map<int, vector<int> > graph;
	map<int, vector<int> >::iterator it;
	map<int, bool> visited;
	map<int, bool> mark;
	map<int, bool>::iterator itM;

	bool tree, ver;
	int start, search, i, aux, cVer, num, count;

	while( cin>>f>>s ){
		if( f < 0 && s < 0 ){
			break;
		}else if( f != 0 && s != 0 ){
			graph[f].push_back(s);
			visited[f] = false;
			visited[s] = false;
			mark[f] = false;
			mark[s] = false;
			inputs++;
		}else{
			c++;
			tree = false;
			cVer = 0;

			for(it = graph.begin(); it != graph.end(); it++){
				vector<int> vAux = it->second;
				for(int i = 0; i < vAux.size(); i++ ){
					num = vAux[i];
					if( num != it->first ){
						mark[ num ] = true;
					}
				}
			}

			for(itM = mark.begin(); itM != mark.end(); itM++ ){
				ver = itM->second;
				if( ver == false ){
					start = itM->first;
					cVer++;
				}
			}

			if( cVer == 1 ){
				tree = true;
			}

			count = 0;
			queue<int> cola;
			cola.push(start);
			visited[start] = true;

			while( !cola.empty() ){
				search = cola.front();
				cola.pop();

				int tam = graph[search].size();
				for( i = 0; i < tam; i++ ){
					aux = graph[search][i];

					if( visited[aux] ){
						tree = false;
					}else{
						visited[aux] = true;
						cola.push(aux);
						count++;
					}
				}
			}

			if( tree && ( ( visited.size() - count ) == 1 ) || inputs == 0){
				printf("Case %d is a tree.\n", c);
			}else{
				printf("Case %d is not a tree.\n", c);
			}

			graph.clear();
			mark.clear();
			visited.clear();
			inputs = 0;
		}
	}

	return 0;
}
