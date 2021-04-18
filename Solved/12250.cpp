/*
*
* Problema UVA 12250 - Language Detection
*
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string line;
	int c = 0;

	while( getline(cin, line) ){
		if(line == "#"){
			break;
		}else{
			c++;
			if( line == "HELLO" ){
				cout << "Case " << c << ": ENGLISH" << endl;
			}else if( line == "HOLA"){
				cout << "Case " << c << ": SPANISH" << endl;
			}else if( line == "HALLO" ){
				cout << "Case " << c << ": GERMAN" << endl;
			}else if( line == "BONJOUR" ){
				cout << "Case " << c << ": FRENCH" << endl;
			}else if( line == "CIAO" ){
				cout << "Case " << c << ": ITALIAN" << endl;
			}else if( line == "ZDRAVSTVUJTE" ){
				cout << "Case " << c << ": RUSSIAN" << endl;
			}else{
				cout << "Case " << c << ": UNKNOWN" << endl;
			}
		}

	}


	return 0;
}