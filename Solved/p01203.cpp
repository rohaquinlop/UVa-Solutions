/*
*
* Problema UVA 1203 - Argus
*
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  int qNum, period, count = 0, i, k, show, first, line, aux;
  string action;
  map <int, int> registro;
  pair <int, int> it;
  priority_queue <pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>>> pq;

  while(1){
    cin >> action;

    if(action == "#"){
      break;
    }else{
      scanf(" %d %d\n", &qNum, &period);
      registro.insert( pair<int, int>(qNum, period) );
      pq.push( make_pair(period, qNum) );
    }
  }

  scanf("%d\n", &k);

  while(k){
    it = pq.top();
    pq.pop();
    cout << it.second << endl;
    it.first += registro[it.second];
    pq.push(it);
    k--;
  }



  /* Recorrido de un mapa */
  /*
  for(it = registro.begin(); it != registro.end(); ++it){
    cout << it->first << " => " << it->second << endl;
  }
  */

  return 0;
}
