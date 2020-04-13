#include <bits/stdc++.h>

using namespace std;

int n, numSCC, t;
vector<vector<int>> graph;
vector<int> visited;
vector<int> secondTag;
stack<int> p, s;

void DFS(int);

void gabow(){
  visited = vector<int>(n, -1);
  secondTag = vector<int>(n, -1);


  for(int i = 0; i < n; ++i){
    if(visited[i] == -1)
      DFS(i);
  }
}

void DFS(int v){
  int w;
  visited[v] = secondTag[v] = ++t;
  p.push(v);
  s.push(v);


  for(int i = 0; i < graph[v].size(); ++i){
    w = graph[v][i];
    if(visited[w] == -1) DFS(w);
    else if(secondTag[w] == -1){
      while(visited[p.top()] > visited[w]){
        p.pop();
      }
    }

    if(v == p.top()){
      numSCC++;
      //cout << "SCC #" << secondTag[v] << ": ";
      while(p.top() != v){

      }
    }
  }

  if(secondTag[v] == visited[v]){
    //cout << "SCC #" << secondTag[v] << ": ";
    while(p.top() != v){
      cout << p.top() << " ";
      secondTag[p.top()] = numSCC-1;
      p.pop();
    }
    cout << p.top() << " ";
    secondTag[p.top()] = numSCC-1;
    p.pop();
    s.pop();
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

  gabow();
}