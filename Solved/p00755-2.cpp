/*
*
* Problema UVA 755 - 487-3279
*
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
#include <iterator>
#include <vector>

using namespace std;

int main(){
  map <string, int> letters;

  letters["A"] = 2;
  letters["B"] = 2;
  letters["C"] = 2;
  letters["D"] = 3;
  letters["E"] = 3;
  letters["F"] = 3;
  letters["G"] = 4;
  letters["H"] = 4;
  letters["I"] = 4;
  letters["J"] = 5;
  letters["K"] = 5;
  letters["L"] = 5;
  letters["M"] = 6;
  letters["N"] = 6;
  letters["O"] = 6;
  letters["P"] = 7;
  letters["R"] = 7;
  letters["S"] = 7;
  letters["T"] = 8;
  letters["U"] = 8;
  letters["V"] = 8;
  letters["W"] = 9;
  letters["X"] = 9;
  letters["Y"] = 9;

  int datasets, cases, i, count, result, enter, band;
  string line, aux, out, value;
  stringstream fill;
  map <string, int>::iterator it;
  map <string, int> numbers;

  scanf("%d\n", &datasets);
  enter = 0;

  while (datasets){

    scanf("\n%d\n", &cases);
    while(cases){
      count = 0;
      fill.str("");
      getline(cin, line);

      for(i = 0; i < line.length(); i++){
        aux = line[i];
        if(aux != "-"){
          if(letters.count(aux)>0){
            fill << letters[aux];
          }else{
            fill<< aux;
          }
          count++;
          if(count == 3){
            fill<<"-";
          }
        }
      }

      out = fill.str();

      it = numbers.find(out);

      if( it != numbers.end() ){
        /* El valor existe */
        it->second += 1;
      }else{
        numbers[out] = 1;
      }

      cases--;
    }

    count = 0;

    if(enter > 0){
      cout << endl;
    }

    band = 1;

    for(it = numbers.begin(); it != numbers.end(); ++it){
      if(it->second > 1){
        band = 0;
        cout << it->first << " " << it->second << endl;
      }
    }

    if(band != 0){
      cout << "No duplicates." << endl;
    }


    numbers.clear();

    datasets--;
    enter++;
  }


  return 0;
}
