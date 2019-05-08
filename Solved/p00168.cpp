/*
*
* Problema UVA 168 - Theseus and the Minotaur
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int tam, i, j, k, lights;
	string line, a, b, t, m, aux, aux1;
	string search;

	while( getline(cin, line) ){
		if(line == "#"){
			break;
		}else{
			map<string, vector<string>> graph;
			map<string, vector<string>>::iterator it;
			map<string, bool> visited;

			tam = line.length();
			j = 0;
			/* Leyendo los datos */
			for(i = 0; i < tam; i++){
				aux = line[i];
				if( aux == ";"){
					for(k=j; k < i; k++){
						aux1 = line[k];
						if(k == j){
							a = aux1;
							visited[a] = false;
						}
						if( aux1 != ":" && k > j ){
							graph[a].push_back(aux1);
							visited[aux1] = false;
						}
					}
					j = k+1;
				}
				if( aux == "."){
					for(k=j; k < i; k++){
						aux1 = line[k];
						if(k == j){
							a = aux1;
						}
						if( aux1 != ":" && k > j ){
							graph[a].push_back(aux1);
						}
					}
					j = k+2;

					aux1 = "";
					for(k = j; k < tam; k++){
						aux1 += line[k];
					}
					char last[aux1.size()+1];
					strcpy(last, aux1.c_str());
					char l1[1], l2[1];

					m = last[0];
					t = last[2];
					sscanf(last, "%*s %*s %d", &lights);
				}
			}

			/* Recorriendo el grafo */
			k = 1;
			vector<string> lighted;

			queue<string> cola;
			cola.push(m);

			while( !cola.empty() ){
				search = cola.front();
				cola.pop();

				/*cout << search << endl;*/

				if(k == lights){
					visited[search] = true;
					lighted.push_back(search);
					/*cout << search<< "!!" << endl;*/
					k = 0;
				}

				tam = graph[search].size();

				for(i = 0; i < tam; i++){
					aux = graph[search][i];
					if( !visited[aux] && aux != t ){
						cola.push(aux);
						t = search;
						k++;
						break;
					}
				}
			}

			for(i = 0; i < lighted.size(); i++){
				if( lighted[i] != search ){
					cout << lighted[i] << " ";
				}
			}
			cout << "/" << search << endl;

		}
	}


	return 0;
}
