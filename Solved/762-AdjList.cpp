/*
*
* Problema UVA 762 - We Ship Cheap
* BFS Listas de adyacencia
*
*/

#include<bits/stdc++.h> 
using namespace std; 

int main(){
	int cases;
	string aux, aux1, start, end;
	int i, j, k, c = 0;
	bool finded;
	int posStart, posEnd;
	while( scanf("%d", &cases) == 1 ){
		set< string > points;
		set< string >::iterator itr;
		vector< vector<string> > pairs;
		vector<string> nodes;

		vector <int> path;
		vector < pair<string, string> > outs;

		map<string, int> vals;
		int change;

		bool connection = false;

		while(cases--){
			vector<string> line;
			cin >> aux;
			line.push_back(aux);
			points.insert(aux);
			cin >> aux1;
			line.push_back(aux1);
			points.insert(aux1);
			pairs.push_back(line);
		}
		cin >> start;
		cin >> end;
		finded = false;

		posStart = -1;
		posEnd = -1;

		if( c > 0)
			cout << endl;

		for( itr = points.begin(); itr != points.end(); itr++ ){
			aux = *itr;
			nodes.push_back(aux);
		}

		for(i = 0; i < nodes.size(); i++){
			aux = nodes[i];
			vals[aux] = i;
			if( start == aux )
				posStart = i;
			if( end == aux)
				posEnd = i;
		}

		vector< vector <int> > adjList(nodes.size());
		for(i = 0; i < pairs.size(); i++){
			j = vals[ pairs[i][0] ];
			k = vals[ pairs[i][1] ];
			adjList[ j ].push_back( k );
			adjList[ k ].push_back( j );
		}

		vector<int> dist( nodes.size(), INT_MAX );
		vector<int> pred( nodes.size(), -1 );

		/* BFS para saber si el nodo inicial se conecta con el nodo final*/
		if( posEnd != -1 && posStart != -1 ){
			vector<int> visited(nodes.size(), false);
			queue <int> cola;

			cola.push(posStart);
			visited[posStart] = true;
			dist[posStart] = 0;

			while( !cola.empty() && connection == false){
				change = cola.front();
				cola.pop();
				/* cout << nodes[change] << " "; */
				for( i = 0; i < adjList[change].size() && connection == false; i++ ){
					if(!visited[ adjList[change][i] ]){
						cola.push( adjList[change][i] );
						visited[ adjList[change][i] ] = true;
						dist[ adjList[change][i] ] = dist[change]+1;
						pred[ adjList[change][i] ] = change;
						if( adjList[change][i] == posEnd ){
							connection = true;
						}
					}
				}
			}
		}

		if( !connection ){
			cout << "No route" << endl;
		}else{
			int crawl = posEnd;
			path.push_back( crawl );
			while( pred[crawl] != -1 ){
				path.push_back( pred[crawl] );
				crawl = pred[crawl];
			}

			for( i = path.size()-1; i > 0; i-- ){
				cout << nodes[ path[i] ] << " " << nodes[ path[i-1] ] << endl;
			}
		}

		c++;
	}


  return 0;
}
