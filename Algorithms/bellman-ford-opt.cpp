/*
Implementacion Algoritmo de Bellman-Ford Optimizado para SSSP
Autor: Carlos Ramirez
Fecha: Abril 24 de 2020

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
vector<bool> enCola(50000);
vector<int> conteo(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
    enCola[i] = false;
    conteo[i] = 0;
  }

  d[s] = 0;
}

bool bellmanFordOpt(int s){
  int i, j, u, v, peso;
  queue<int> cola;
  
  inicializar(s);
  cola.push(s);
  enCola[s] = true;
  
  while(!cola.empty()){
    u = cola.front();
    cola.pop();
    enCola[u] = false;

    for(i = 0; i < adj[u].size(); ++i){
      v = adj[u][i].first;
      peso = adj[u][i].second;
      if(d[u] != INT_MAX && d[u] + peso < d[v]){
        d[v] = d[u] + peso;
        p[v] = u;

        if(!enCola[v]){
          cola.push(v);
          enCola[v] = true;
          conteo[v]++;

          //verifica si encontro un ciclo negativo
          if(conteo[v] > n)
            return false;
        }
      }
    }
  }

  return true;
}

int main(){
  int m, i, aux1, aux2, peso;

  cin >> n >> m;

  for(i = 0; i < m; i++){
    cin >> aux1 >> aux2 >> peso;
    adj[aux1].push_back(make_pair(aux2, peso));
  }

  if(bellmanFordOpt(0)){
    for(i = 0; i < n; ++i)
      cout << "Distancia a nodo " << i << ": " << d[i] << endl;

    for(i = 0; i < n; ++i)
      cout << "Predecesor nodo " << i << ": " << p[i] << endl;
  }
  else
    cout << "El grafo tiene ciclos negativos" << endl;
  
  return 0;
}
