#include <bits/stdc++.h>
using namespace std;

int numSCC, t;
stack<int> p;
map<int, int> SCC;

void tarjan(map<int, vector<int>>& graph, map<int, int>& visited, map<int, int>& secondTag, map<int, int>& isInStack){
  map<int, vector<int>>::iterator it;
  for(it = graph.begin(); it != graph.end(); it++){
    if(!visited[it->first])
      DFS(it->first, graph, visited, secondTag, isInStack);
  }
}

void DFS(int v, map<int, vector<int>>& graph, map<int, int>& visited, map<int, int>& secondTag, map<int, int>& isInStack){
  int w;
  visited[v] = secondTag[v] = ++t;
  p.push(v);
  isInStack[v] = 1;

  for(int i = 0; i < graph[v].size(); ++i){
    w = graph[v][i];
    if(visited[w] == -1) DFS(w,graph, visited, secondTag, isInStack);
    if(isInStack[w])
      secondTag[v] = secondTag[v] < secondTag[w] ? secondTag[v] : secondTag[w];
  }

  if(secondTag[v] == visited[v]){
    while(p.top() != v){
      SCC[p.top()] = secondTag[v];
      isInStack[p.top()] = 0;
      p.pop();
    }
    SCC[p.top()] = secondTag[v];
    isInStack[p.top()] = 0;
    p.pop();
  }
}


int main(){



  return 0;
}