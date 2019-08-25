/*
*
* Problema UVA 11988 - Broken Keyboard (a.k.a. Beiju Text)
*
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int i, pos;
	char instruction;
	string line;

	while( cin >> line ){
		list<char> v;
		list<char>::iterator it = v.end();
		for(i = 0; i < line.size(); i++){
			if( line[i] == '[' )
				it = v.begin();
			else if( line[i] == ']' )
				it = v.end();
			else
				v.insert(it, line[i]);
		}

		for(it = v.begin(); it != v.end(); it++)
			printf("%c", *it);
		printf("\n");
	}


	return 0;
}