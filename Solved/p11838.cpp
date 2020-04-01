/*
*
* Problema UVa 11838 - Come and Go
*
*/

#include<bits/stdc++.h>

using namespace std;
stack<int> pila;
int SCC;

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
}

void kosaraju(vector<vector<int>> &graph, vector<vector<int>> &graphT, vector<int> &visited1, vector<int> &visited2){
	//Start first DFS Toposort
  int i;
  for(i = 0; i < graph.size(); ++i)
    if(!visited1[i]) DFS1(i, graph, visited1);

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
  int n, m, i;
  int a, b, c;

  while(cin >> n >> m){
    if(!n and !m) break;
    vector<int> visited1(n, 0);
    vector<int> visited2(n, 0);
    vector<vector<int>> graph(n, vector<int>(0));
    vector<vector<int>> graphT(n, vector<int>(0));
  	pila = stack<int>();
  	SCC = 0;

    //Input
    for(i = 0; i < m; ++i){
      cin >> a >> b >> c;
      --a, --b;
      if(c == 1){
        graph[a].push_back(b);
        graphT[b].push_back(a);
      }
      else{
        graph[a].push_back(b);
        graph[b].push_back(a);
        graphT[a].push_back(b);
        graphT[b].push_back(a);
      }
    }

    kosaraju(graph, graphT, visited1, visited2);
    
    if(SCC == 1) cout << "1\n";
    else cout << "0\n";
  }


  return 0;
}