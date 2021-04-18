/*
*
* Problema UVA 429 - Word Transformation
*
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int cDiff(string a, string b){
	int diff = 0, i;

	if( a.size() == b.size() ){
		for(i = 0; i < a.size(); i++ ){
			if( a[i] == b[i] ){
				diff++;
			}
		}
	}
	return (a.size()-diff);
}

int mapRoute( map<string, string> r, string s, string e){
	int dist = 0;

	while( s != e ){
		dist++;
		e = r[e];
	}

	return dist;
}

int main(){
	int n, tam, i, c = 0;
	string word, start, end, search, aux, line;

	cin >> n;

	while(n--){
		c++;

		if(c > 1){
			printf("\n");
		}

		vector<string> words;
		map<string, vector<string> > graph;
		map<string, bool> visited;
		vector<string>::iterator it;
		vector<string>::iterator it1;
		map<string, bool>::iterator it2;

		while(cin >> word){
			if( word == "*" ){
				break;
			}else{
				words.push_back(word);
				visited[word] = false;
			}
		}

		cin.ignore();

		/*Generar grafo*/
		for(it = words.begin(); it != words.end(); it++){
			for(it1 = words.begin(); it1 != words.end(); it1++){
				word = *it;
				aux = *it1;
				if( cDiff(word, aux) == 1 ){
					graph[word].push_back(aux);
					graph[aux].push_back(word);
				}
			}
		}


		while( getline(cin, line) && line != "" ){
			stringstream ss(line);
			ss >> start >> end;

			for(it2 = visited.begin(); it2 != visited.end(); it2++){
				it2->second = false;
			}

			/*Recorrer grafo*/
			map<string, string> route;
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

					for(i = 0; i < tam; i++){
						aux = graph[search][i];

						if( !visited[aux] ){
							visited[aux] = true;
							cola.push(aux);
							route[aux] = search;
						}
					}
				}
			}

			printf("%s %s %d\n", start.c_str(), end.c_str(), mapRoute(route, start, end) );
		}
	}


	return 0;
}