/*
*
* Problema UVa 540 - Team Queue
*
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
  int t, n, a, i, j, c = 0, posQueue;

  while(cin >> t){
    ++c;
    if(!t) break;

    map<int, int> nTeam;
    vector< queue<int> > teamQueue;
    vector<int> posTeam(t, -1);
    posQueue = 0;

    for(i = 0; i < t; ++i){
      cin >> n;
      for(j = 0; j < n; ++j){
        cin >> a;
        nTeam[a] = i;
      }
    }

    string s;
    //s puede tomar valores entre STOP, ENQUEUE x, DEQUEUE

    cout << "Scenario #" << c << "\n";

    while(cin >> s){
      if( s == "STOP") break;
      else if( s == "ENQUEUE"){
        cin >> a;
        i = nTeam[a]; //Equipo al que pertenece a
        j = posTeam[i]; //Posición en donde se encuentra el equipo en el vector
        if( j != -1 ){
          teamQueue[j].push(a);
        }
        else{
          /*
          queue<int> q; //creando una cola
          teamQueue.push_back(q); //Agregar una cola
          teamQueue[teamQueue.size()-1].push(a); // Opcion 1
          */
          queue<int> q; //Creando una cola
          q.push(a); //Agregando el nuevo elemento a la cola
          teamQueue.push_back(q); //Agregando la nueva cola al vector
          posTeam[i] = teamQueue.size()-1;
        }
      }
      else{
        //Tomando el primer elemento de la Team Queue y eliminando el primer elemento
        a = teamQueue[posQueue].front();
        teamQueue[posQueue].pop();

        //Hay que asegurarse que la cola en la primera posicion de memoria no este vacía
        if( teamQueue[posQueue].empty() ){
          ++posQueue;
          i = nTeam[a];
          posTeam[i] = -1;
        }
        cout << a << "\n";
        //cout << a << " pos in Team Queue: " << j << "\n";
        // //- - - -
        // vector<int> nums = {0, 1, 2, 3};
        // vector<int>::iterator it;
        // for(it = nums.begin(); it != nums.end(); ++it)
      }
    }
    cout << "\n";

  }


  return 0;
}