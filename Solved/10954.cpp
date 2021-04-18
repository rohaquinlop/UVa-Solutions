/*
*
* Problema UVA 10954 - Add All
*
*/

#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
  int cases, i;
  long int aux, cost1, cost2, cost3;
  priority_queue< long int, vector<long int>, greater<long int> > q;

  while (scanf("%d\n", &cases) == 1) {
    if(cases == 0){
      break;
    }else{

      for(i = 0; i < cases; i++){
        scanf("%li", &aux);
        q.push(aux);
      }

      cost3 = 0;

      while( q.size() > 1 ){
        cost1 = q.top();
        q.pop();
        cost2 = q.top();
        q.pop();
        cost3 += cost1+cost2;
        q.push(cost1+cost2);
      }

      q.pop();

      cout << cost3 << endl;


    }
  }


  return 0;
}
