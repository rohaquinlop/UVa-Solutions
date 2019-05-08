/*
*
* Problema UVA 11586 - Train Tracks
*
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int cases, i, band; /* Casos */
  string line; /* Linea que contiene las piezas */
  int Ms, Fs;
  string aux;

  scanf("%d\n", &cases);

  while(cases) {
    Ms = 0;
    Fs = 0;
    band = 0;

    getline(cin,line);

    for(i = 0; i < line.length(); i++){
      aux = line[i];
      if(aux != " "){

        if( aux == "M" ){
          Ms++;
          band++;
        }else{
          Fs++;
          band++;
        }

      }
    }

    if(Ms == Fs && band > 2){
      cout << "LOOP" << endl;
    }else{
      cout << "NO LOOP" << endl;
    }

    cases--;
  }

  return 0;
}
