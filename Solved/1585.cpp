/*
*
* Problema UVA 1585 - Score
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases;
	string line;
	int count, i, consec;

	cin >> cases;

	while(cases--){
		cin >> line;

		count = 0;
		consec = 0;

		for(i = 0; i < line.size(); i++){
			if( line[i] == 'O'){
				consec++;
				count += consec;
			}else if( line[i] == 'X'){
				consec = 0;
			}
		}

		printf("%d\n", count);
	}


	return 0;
}
