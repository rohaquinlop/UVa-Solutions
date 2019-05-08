/*
*
* Problema UVA 439 - Knight Moves
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int tam, i, cMoves;
	string a, b, aux, search;

	map<string, vector<string> > graph;
	map<string, vector<string> >::iterator it;

	graph["a1"] = {"b3", "c2"};
	graph["a2"] = {"b4", "c1", "c3"};
	graph["a3"] = {"b1", "b5", "c2", "c4"};
	graph["a4"] = {"b2", "b6", "c3", "c5"};
	graph["a5"] = {"b3", "b7", "c4", "c6"};
	graph["a6"] = {"b4", "b8", "c5", "c7"};
	graph["a7"] = {"b5", "c6", "c8"};
	graph["a8"] = {"b6", "c7"};

	graph["b1"] = {"a3", "c3", "d2"};
	graph["b2"] = {"a4", "c4", "d1", "d3"};
	graph["b3"] = {"a1", "a5", "c1", "c5", "d2", "d4"};
	graph["b4"] = {"a2", "a6", "c2", "c6", "d3", "d5"};
	graph["b5"] = {"a3", "a7", "c3", "c7", "d4", "d6"};
	graph["b6"] = {"a4", "a8", "c4", "c8", "d5", "d7"};
	graph["b7"] = {"a5", "c5", "d6", "d8"};
	graph["b8"] = {"a6", "c6", "d7"};

	graph["c1"] = {"a2", "b3", "d3", "e2"};
	graph["c2"] = {"a1", "a3", "b4", "d4", "e1", "e3"};
	graph["c3"] = {"a2", "a4", "b1", "b5", "d1", "d5", "e2", "e4"};
	graph["c4"] = {"a3", "a5", "b2", "b6", "d2", "d6", "e3", "e5"};
	graph["c5"] = {"a4", "a6", "b3", "b7", "d3", "d7", "e4", "e6"};
	graph["c6"] = {"a5", "a7", "b4", "b8", "d4", "d8", "e5", "e7"};
	graph["c7"] = {"a6", "a8", "b5", "d5", "e6", "e8"};
	graph["c8"] = {"a7", "b6", "d6", "e7"};

	graph["d1"] = {"b2", "c3", "e3", "f2"};
	graph["d2"] = {"b1", "b3", "c4", "e4", "f1", "f3"};
	graph["d3"] = {"b2", "b4", "c1", "c5", "e1", "e5", "f2", "f4"};
	graph["d4"] = {"b3", "b5", "c2", "c6", "e2", "e6", "f3", "f5"};
	graph["d5"] = {"b4", "b6", "c3", "c7", "e3", "e7", "f4", "f6"};
	graph["d6"] = {"b5", "b7", "c4", "c8", "e4", "e8", "f5", "f7"};
	graph["d7"] = {"b6", "b8", "c5", "e5", "f6", "f8"};
	graph["d8"] = {"b7", "c6", "e6", "f7"};

	graph["e1"] = {"c2", "d3", "f3", "g2"};
	graph["e2"] = {"c1", "c3", "d4", "f4", "g1", "g3"};
	graph["e3"] = {"c2", "c4", "d1", "d5", "f1", "f5", "g2", "g4"};
	graph["e4"] = {"c3", "c5", "d2", "d6", "f2", "f6", "g3", "g5"};
	graph["e5"] = {"c4", "c6", "d3", "d7", "f3", "f7", "g4", "g6"};
	graph["e6"] = {"c5", "c7", "d4", "d8", "f4", "f8", "g5", "g7"};
	graph["e7"] = {"c6", "c8", "d5", "f5", "g6", "g8"};
	graph["e8"] = {"c7", "d6", "f6", "g7"};

	graph["f1"] = {"d2", "e3", "g3", "h2"};
	graph["f2"] = {"d1", "d3", "e4", "g4", "h1", "h3"};
	graph["f3"] = {"d2", "d4", "e1", "e5", "g1", "g5", "h2", "h4"};
	graph["f4"] = {"d3", "d5", "e2", "e6", "g2", "g6", "h3", "h5"};
	graph["f5"] = {"d4", "d6", "e3", "e7", "g3", "g7", "h4", "h6"};
	graph["f6"] = {"d5", "d7", "e4", "e8", "g4", "g8", "h5", "h7"};
	graph["f7"] = {"d6", "d8", "e5", "g5", "h6", "h8"};
	graph["f8"] = {"d7", "e6", "g6", "h7"};

	graph["g1"] = {"e2", "f3", "h3"};
	graph["g2"] = {"e1", "e3", "f4", "h4"};
	graph["g3"] = {"e2", "e4", "f1", "f5", "h1", "h5"};
	graph["g4"] = {"e3", "e5", "f2", "f6", "h2", "h6"};
	graph["g5"] = {"e4", "e6", "f3", "f7", "h3", "h7"};
	graph["g6"] = {"e5", "e7", "f4", "f8", "h4", "h8"};
	graph["g7"] = {"e6", "e8", "f5", "h5"};
	graph["g8"] = {"e7", "f6", "h6"};

	graph["h1"] = {"f2", "g3"};
	graph["h2"] = {"f1", "f3", "g4"};
	graph["h3"] = {"f2", "f4", "g1", "g5"};
	graph["h4"] = {"f3", "f5", "g2", "g6"};
	graph["h5"] = {"f4", "f6", "g3", "g7"};
	graph["h6"] = {"f5", "f7", "g4", "g8"};
	graph["h7"] = {"f6", "f8", "g5"};
	graph["h8"] = {"f7", "g6"};

	while( cin>>a>>b ){
		queue<string> cola;
		cMoves = 0;

		map<string, bool> visited;
		map<string, string> route;
		map<string, string>::iterator itR;

		for(it = graph.begin(); it != graph.end(); it++){
			aux = it->first;
			visited[aux] = false;
		}

		cola.push(a);
		visited[a] = true;

		while( !cola.empty() ){
			search = cola.front();
			cola.pop();

			if(search == b){
				break;
			}else{
				tam = graph[search].size();
				for(i = 0; i < tam; i++){
					aux = graph[search][i];
					if( !visited[aux] ){
						cola.push(aux);
						visited[aux] = true;
						route[aux] = search;
					}
				}
			}
		}

		search = b;

		while( search != a ){
			search = route[search];
			cMoves++;
		}

		cout << "To get from " << a << " to " << b << " takes " << cMoves << " knight moves." << endl;

	}

	return 0;
}
