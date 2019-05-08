/*
*
* Problema UVA 12554 - A Special “Happy Birthday” Song!!!
*
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> family;
	string line;
	vector<string> song {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

	int names, i, j, k, rounds;

	scanf("%d", &names);

	while(names--){
		cin >> line;
		family.push_back(line);
	}
	rounds = family.size()/song.size();
	rounds++;

	k = 0;

	for(i = 0; i < rounds; i++){
		for(j = 0; j < song.size(); j++){
			cout << family[k] << ": " << song[j] << endl;
			k++;
			if(k == family.size()){
				k = 0;
			}
		}
	}

	return 0;
}