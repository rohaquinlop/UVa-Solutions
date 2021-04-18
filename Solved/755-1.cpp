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

  int datasets, cases, i, count, result, enter;
  string line, aux, out, value;
  stringstream fill;
  vector<string> numbers;
  set <string> unicos;
  set <string>::iterator it;

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
          fill<<line[i];
          count++;
          if(count == 3){
            fill<<"-";
          }
        }
      }

      out = fill.str();
      count = 0;
      fill.str("");

      for(i = 0; i < out.length(); i++){
        aux = out[i];
        if(aux != "-"){
          if(letters.count(aux)>0){
            fill << letters[aux];
          }else{
            fill<< aux;
          }
        }else{
          fill<<"-";
        }
      }
      out = fill.str();

      numbers.push_back(out);
      unicos.insert(out);

      cases--;
    }

    count = 0;

    if(enter > 0){
      cout << endl;
    }

    for(it = unicos.begin(); it != unicos.end(); ++it ){
      value = *it;
      result = std::count(numbers.begin(), numbers.end(), value);
      if (result > 1){
          cout << value << " " << result << endl;
      }else{
        count++;
      }
    }

    if(count == numbers.size()){
      cout << "No duplicates." << endl;
    }


    numbers.clear();
    unicos.clear();

    datasets--;
    enter++;
  }


  return 0;
}
