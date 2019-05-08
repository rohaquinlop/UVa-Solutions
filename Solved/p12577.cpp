/*
*
* Problema UVA 12577 - Hajj-e-Akbar
*
*/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
	string palabra;
	int pos = 0;

	while(true){
		cin >> palabra;
		pos++;
		if( palabra.compare("*") == 0 ){
			break;
		}
		if( palabra.compare("Hajj") == 0 ){
			printf("Case %d: Hajj-e-Akbar\n", pos);
		}
		if( palabra.compare("Umrah") == 0 ){
			printf("Case %d: Hajj-e-Asghar\n", pos);
		}
	}

	return 0;
}