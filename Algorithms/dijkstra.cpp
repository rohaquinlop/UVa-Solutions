/*
Implementacion Algoritmo de Dijkstra para SSSP
Autor: Carlos Ramirez
Fecha: Abril 25 de 2020

*/

#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<int> p(50000);
vector<int> d(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

void dijkstra(int s){
  int i, j, k, u, v, peso, costo;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
      for(j = 0; j < adj[u].size(); ++j){
	v = adj[u][j].first;
	peso = adj[u][j].second;
	if(d[u] != INT_MAX && d[u] + peso < d[v]){
	  d[v] = d[u] + peso;
	  p[v] = u;
	  cola.push(make_pair(d[v], v));
	}
      }
    }
  }
}

int main(){
  int m, i, aux1, aux2, peso;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2 >> peso;
    adj[aux1].push_back(make_pair(aux2, peso));
  }

  dijkstra(0);

  for(i = 0; i < n; ++i)
    cout << "Distancia a nodo " << i << ": " << d[i] << endl;

  for(i = 0; i < n; ++i)
    cout << "Predecesor nodo " << i << ": " << p[i] << endl;
  
  return 0;
}
