/*
*
* Problema UVA 10082 - WERTYU
*
*/

#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

int main(){

	map<string, string> words;

	words["1"] = "`";
	words["2"] = "1";
	words["3"] = "2";
	words["4"] = "3";
	words["5"] = "4";
	words["6"] = "5";
	words["7"] = "6";
	words["8"] = "7";
	words["9"] = "8";
	words["0"] = "9";
	words["-"] = "0";
	words["="] = "-";

	words["W"] = "Q";
	words["E"] = "W";
	words["R"] = "E";
	words["T"] = "R";
	words["Y"] = "T";
	words["U"] = "Y";
	words["I"] = "U";
	words["O"] = "I";
	words["P"] = "O";
	words["["] = "P";
	words["]"] = "[";
	words["\\"] = "]";

	words["S"] = "A";
	words["D"] = "S";
	words["F"] = "D";
	words["G"] = "F";
	words["H"] = "G";
	words["J"] = "H";
	words["K"] = "J";
	words["L"] = "K";
	words[";"] = "L";
	words["'"] = ";";

	words["X"] = "Z";
	words["C"] = "X";
	words["V"] = "C";
	words["B"] = "V";
	words["N"] = "B";
	words["M"] = "N";
	words[","] = "M";
	words["."] = ",";
	words["/"] = ".";

	string line, aux, out;
	int i;

	while( getline(cin, line) ){
		for(i = 0; i < line.length(); i++){
			aux = line[i];

			if( aux == " " ){
				printf(" ");
			}else{
				cout << words[aux];
			}
		}
		cout << endl;
	}

	return 0;
}