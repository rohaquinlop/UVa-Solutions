/*
*
* Problema UVa 247 - Calling Circles
*
*/

#include <bits/stdc++.h>

using namespace std;
stack<string> pila;
int SCC;
vector<vector<string>> connectedComponents;

void DFS1(string s, map<string, vector<string>> &graph, map<string, bool> &m){
	m[s] = true;
	vector<string> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		string a = v[i];
		if(!m[a]) DFS1(a, graph, m);
	}
	pila.push(s);
}

void DFS2(string s, map<string, vector<string>> &graph, map<string, bool> &m){
	m[s] = true;
	vector<string> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		string a = v[i];
		if(!m[a]) DFS2(a, graph, m);
	}
	connectedComponents[SCC].push_back(s);
}

void kosaraju(map<string, vector<string>> &graph, map<string, vector<string>> &graphT, map<string, bool> &visited1, map<string, bool> &visited2, queue<string> &path){
	map<string, vector<string>>::iterator it;
	//Start first DFS Toposort
	for(it = graph.begin(); it != graph.end(); ++it){
		if(!visited1[it->first]) DFS1(it->first, graph, visited1);
	}

	//Do DFS in transpose graph
	while(!pila.empty()){
		string s = pila.top();
		pila.pop();

		if(!visited2[s]){
			DFS2(s, graphT, visited2);
			++SCC;
		}
	}

}

int main(){
  int n, m, i, c = 0;
  string s1, s2;

  while(cin >> n >> m){
  	if(!n and !m) break;
  	//Initialization
  	++c;
  	connectedComponents = vector<vector<string>>(n);
  	pila = stack<string>();
  	SCC = 0;
    map<string, vector<string>>graph;
    map<string, vector<string>>graphT;
    map<string, bool>visited1;
    map<string, bool>visited2;
    queue<string> path;

    //Input
    for(i=0; i<m; ++i){
    	cin >> s1 >> s2;
    	graph[s1].push_back(s2);
    	graphT[s2].push_back(s1);
    	visited1[s1] = false;
    	visited2[s1] = false;
    	visited1[s2] = false;
    	visited2[s2] = false;
    	path.push(s1);
    	path.push(s2);
    }

    kosaraju(graph, graphT, visited1, visited2, path);
    if(c>1) cout << "\n";
    cout << "Calling circles for data set " << c << ":\n";
    for(i = 0; i < SCC; ++i){
    	for(int j = 0; j < connectedComponents[i].size(); ++j){
    		cout << connectedComponents[i][j];
    		if(j < connectedComponents[i].size()-1) cout << ", ";
    	}
    	cout << "\n";
    }
  }

  return 0;
}