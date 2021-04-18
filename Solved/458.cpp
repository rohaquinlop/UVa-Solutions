/*
*
* Problema UVA 458 - The Decoder
*
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int i, j;
	string line;

	while( getline(cin, line) ){
		i = line.length();
		char letters[i+1];
		strcpy(letters, line.c_str());
		for( j = 0; j < i; j++ ){
			printf("%c", letters[j]-7);
		}
		printf("\n");
	}


	return 0;
}