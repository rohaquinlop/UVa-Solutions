#include <bits/stdc++.h>

using namespace std;
stack<int> pila;
int SCC;
vector<vector<int>> connectedComponents;

void DFS1(int s, vector<vector<int>> &graph, vector<int> &m){
	m[s] = 1;
	vector<int> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		int a = v[i];
		if(!m[a]) DFS1(a, graph, m);
	}
	pila.push(s);
}

void DFS2(int s, vector<vector<int>> &graph, vector<int> &m){
	m[s] = 1;
	vector<int> v = graph[s];
	for(int i = 0; i < v.size(); ++i ){
		int a = v[i];
		if(!m[a]) DFS2(a, graph, m);
	}
	connectedComponents[SCC].push_back(s);
}

void kosaraju(vector<vector<int>> &graph, vector<vector<int>> &graphT, vector<int> &visited1, vector<int> &visited2){
	//Start first DFS Toposort
	for(int i = 0; i < graph.size(); ++i){
		if(!visited1[i]) DFS1(i, graph, visited1);
	}

	//Do DFS in transpose graph
	while(!pila.empty()){
		int s = pila.top();
		pila.pop();

		if(!visited2[s]){
			DFS2(s, graphT, visited2);
			++SCC;
		}
	}

}

int main(){
  int n, m, i, c = 0;
  int s1, s2;

  while(cin >> n >> m){
  	if(!n and !m) break;
  	//Initialization
  	++c;
  	connectedComponents = vector<vector<int>>(n);
  	pila = stack<int>();
  	SCC = 0;
    vector<vector<int>>graph;
    vector<vector<int>>graphT;
    vector<int>visited1(n, 0);
    vector<int>visited2(n, 0);

    //Input
    for(i=0; i<m; ++i){
    	cin >> s1 >> s2;
    	graph[s1].push_back(s2);
    	graphT[s2].push_back(s1);
    }

    kosaraju(graph, graphT, visited1, visited2);
  }

  return 0;
}