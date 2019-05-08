/*
*
* Problema UVA 12403 - Save Setu
*
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	int cases, count = 0, n;
	string line;

	scanf("%d", &cases);

	while(cases--){
		cin >> line;
		if( line == "donate" ){
			scanf("%d", &n);
			count += n;
		}else if( line == "report" ){
			cout << count << endl;
		}

	}


	return 0;
}