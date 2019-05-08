/*
*
* Problema UVA 12289 - One-Two-Three
*
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	string line, aux1, aux2, aux3;
	int cases;

	scanf("%d", &cases);

	while(cases--){
		cin >> line;
		aux1 = line[0];
		aux2 = line[1];
		aux3 = line[2];

		if( line.length() == 3 ){
			if( aux1 == "o" && aux2 == "n"){
				cout << "1" << endl;
			}else if( aux1 == "o" && aux3 == "e"){
				cout << "1" << endl;
			}else if( aux2 == "n" && aux3 == "e" ){
				cout << "1" << endl;
			}else if( aux1 == "t" && aux2 == "w"){
				cout << "2" << endl;
			}else if( aux1 == "t" && aux3 == "o" ){
				cout << "2" << endl;
			}else if( aux2 == "w" && aux3 == "o"){
				cout << "2" << endl;
			}
		}else if( line.length() == 5 ){
			cout << "3" << endl;
		}
	}


	return 0;
}