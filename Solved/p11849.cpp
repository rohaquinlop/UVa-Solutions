/*
*
* Problema UVA 11849 - CD
*
*/

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int cN, cM, i, j, aux, count;
  set<int> vN;
  set<int> vM;
  set<int> intersection;

  while( scanf("%d %d\n", &cN, &cM) == 2 ){
    if(cN == 0 && cM == 0){
      break;
    }else{
      count = 0;
      for(i = 0; i < cN; i++){
        scanf("%d\n", &aux);
        vN.insert(aux);
      }

      for(i = 0; i < cM; i++){
        scanf("%d\n", &aux);
        vM.insert(aux);
      }

      set_intersection(vN.begin(), vN.end(), vM.begin(), vM.end(), inserter(intersection, intersection.begin() ));

      cout << intersection.size() << endl;

      vN.clear();
      vM.clear();
      intersection.clear();

    }
  }

  return 0;
}
