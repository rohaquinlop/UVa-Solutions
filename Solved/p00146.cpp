/*
*
* Problema UVA 146 - ID Codes
*
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare( string a, string b ){
	return a > b;
}

int main(){
	string perm, aux;

	while( cin >> perm ){
		if( perm == "#" ){
			break;
		}else{
			if( next_permutation(perm.begin(), perm.end()) ){
				printf("%s\n", perm.c_str());
			}else{
				printf("No Successor\n");
			}
		}
	}

	return 0;
}
