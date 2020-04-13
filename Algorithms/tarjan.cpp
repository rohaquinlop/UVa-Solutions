#include <bits/stdc++.h>

using namespace std;

int n, numSCC, t;
vector<vector<int>> graph;
vector<int> visited;
vector<int> secondTag;
vector<int> isInStack;
stack<int> p;

void DFS(int);

void tarjan(){
  visited = vector<int>(n, -1);
  secondTag = vector<int>(n, -1);
  isInStack = vector<int>(n, 0);

  for(int i = 0; i < n; ++i){
    if(visited[i] == -1)
      DFS(i);
  }
}

void DFS(int v){
  int w;
  visited[v] = secondTag[v] = ++t;
  p.push(v);
  isInStack[v] = 1;

  for(int i = 0; i < graph[v].size(); ++i){
    w = graph[v][i];
    if(visited[w] == -1) DFS(w);
    if(isInStack[w])
      secondTag[v] = secondTag[v] < secondTag[w] ? secondTag[v] : secondTag[w];
  }

  if(secondTag[v] == visited[v]){
    //cout << "SCC #" << secondTag[v] << ": ";
    while(pila.top() != v){
      cout << pila.top() << " ";
      isInStack[pila.top()] = 0;
      pila.pop();
    }
    cout << pila.top() << " ";
    isInStack[pila.top()] = 0;
    pila.pop();
  }
}

int main(){
  int m, s1, s2;

  while(cin >> n >> m){
    t = 0;
    for(int i = 0; i < m; ++i){
      cin >> s1 >> s2;
      graph[s1].push_back(s2);
    }
  }

  tarjan();
}