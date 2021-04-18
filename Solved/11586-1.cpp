/*
*
* Problema UVA 11586 - Train Tracks
*
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int cases, count, i;
  vector<string> vCases(51);
  int loop; /* Es true */
  string track;
  stringstream aux1;
  string aux2;
  int iM, iF, dM, dF;
  string izquierda, derecha;
  int band;

  /* int subcases; */

  scanf("%d\n", &cases);

  while(cases){
    loop = 1;
    count = 0;
    iM = 0;
    iF = 0;
    dM = 0;
    dF = 0;
    band = 0;

    /*
    cin >> subcases;

    while (subcases--) {
      cin >> track;
      vCases[count] = track;
      count++;
    }
    */

    getline(cin, track);

    for(i = 0; i < track.size(); i++){
      if(track[i] != ' '){
        aux1.str("");
        aux1 << track[i] << track[i+1];
        aux2 = aux1.str();
        vCases[count] = aux2;
        count++;
        i++;
      }
    }
    count--;


    if(count > 0){

      for(i = 0; i <= count; i++){
        izquierda = vCases[i][0];
        derecha = vCases[i][1];
        if( izquierda != derecha && izquierda.compare("M") == 0){
          band++;
          iM++;
          dF++;
        }
        if( izquierda != derecha && izquierda.compare("F") == 0){
          band++;
          iF++;
          dM++;
        }
        if( izquierda == derecha && izquierda.compare("F") == 0){
          band++;
          iF++;
          dF++;
        }
        if( izquierda == derecha && izquierda.compare("M") == 0){
          band++;
          iM++;
          dM++;
        }
      }
    }

    if( ( (iM+dM) == (iF+dF) ) && band > 1){
      cout << "LOOP" << endl;
    }else{
      cout << "NO LOOP" << endl;
    }

    /*
    if(loop == 1){
      cout << "LOOP" << endl;
    }else{
      cout << "NO LOOP" << endl;
    }
    */


    cases--;
  }


  return 0;
}
