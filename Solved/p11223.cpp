/*
*
* Problema UVA 11223 - O: dah, dah, dah!
*
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(){
  int cases, init, end, i, j, count, number, blank, space;
  string line, aux, aux1, fill2, out;
  stringstream fill;

  vector<string> code, phrase;
  map<string, string> meaning;

  meaning[".-"] = "A";
  meaning["-..."] = "B";
  meaning["-.-."] = "C";
  meaning["-.."] = "D";
  meaning["."] = "E";
  meaning["..-."] = "F";
  meaning["--."] = "G";
  meaning["...."] = "H";
  meaning[".."] = "I";
  meaning[".---"] = "J";
  meaning["-.-"] = "K";
  meaning[".-.."] = "L";
  meaning["--"] = "M";
  meaning["-."] = "N";
  meaning["---"] = "O";
  meaning[".--."] = "P";
  meaning["--.-"] = "Q";
  meaning[".-."] = "R";
  meaning["..."] = "S";
  meaning["-"] = "T";
  meaning["..-"] = "U";
  meaning["...-"] = "V";
  meaning[".--"] = "W";
  meaning["-..-"] = "X";
  meaning["-.--"] = "Y";
  meaning["--.."] = "Z";
  meaning["-----"] = "0";
  meaning[".----"] = "1";
  meaning["..---"] = "2";
  meaning["...--"] = "3";
  meaning["....-"] = "4";
  meaning["....."] = "5";
  meaning["-...."] = "6";
  meaning["--..."] = "7";
  meaning["---.."] = "8";
  meaning["----."] = "9";
  meaning[".-.-.-"] = ".";
  meaning["--..--"] = ",";
  meaning["..--.."] = "?";
  meaning[".----."] = "\'";
  meaning["-.-.--"] = "!";
  meaning["-..-."] = "/";
  meaning["-.--."] = "(";
  meaning["-.--.-"] = ")";
  meaning[".-..."] = "&";
  meaning["---..."] = ":";
  meaning["-.-.-."] = ";";
  meaning["-...-"] = "=";
  meaning[".-.-."] = "+";
  meaning["-....-"] = "-";
  meaning["..--.-"] = "_";
  meaning[".-..-."] = "\"";
  meaning[".--.-."] = "@";

  number = 1;

  scanf("%d\n", &cases);


  while(cases){
    out = "";
    init = 0;
    end = 0;
    blank = 0;
    space = 0;

    getline(cin,line);

    for(i = 0; i < line.length(); i++){
      fill.str("");
      aux = line[i];
      aux1 = line[i+1];

      if(aux == " " && aux1 == " " && space == 0){
        space++;

        end = i;
        /* Ciclo para añadir las letras al arreglo */

        for(j = init; j < end; j++){
          fill<<line[j];
        }
        fill2 = fill.str();

        if(blank > 0){
          fill2.erase(0,1);
        }

        code.push_back(fill2);

        /* cout << fill2 << endl; */

        fill2 = " ";
        code.push_back(fill2);

        /* Fin del ciclo para añadir las letras */
        blank++;

        init = i+2;
      }

      else if(aux == " " && aux1 != " "){
        space = 0;
        end = i;
        /* Ciclo para añadir las letras al arreglo */

        for(j = init; j < end; j++){
          fill<<line[j];
        }
        fill2 = fill.str();

        if(blank > 0){
          fill2.erase(0,1);
        }

        code.push_back(fill2);

        /* cout << fill2 << endl; */

        /* Fin del ciclo para añadir las letras */

        init = i;
        blank++;
      }
      else if( i == (line.length()-1) ){
        end = i;
        for(j = init; j <= end; j++){
          fill<<line[j];
        }
        fill2 = fill.str();

        fill2.erase(0,1);

        code.push_back(fill2);

        /* cout << fill2 << endl; */
      }

    }
    blank = 0;


    /* Descifrando el mensaje */

    for(i = 0; i < code.size(); i++){
      aux1 = code[i];
      if(aux1 == " " && blank > 0){
        phrase.push_back(aux1);
        blank = 0;
      }
      else if(aux1 != " "){
        phrase.push_back(meaning[aux1]);
        blank++;
      }
    }

    if(number > 1){
      cout << endl;
    }

    cout << "Message #" << number << endl;
    for(i = 0; i < phrase.size(); i++){
      cout << phrase[i];
    }
    cout << endl;
    number++;


    cases--;
    code.clear();
    phrase.clear();
  }

  return 0;
}
