/*
*
* Problema UVA 494 - Kindergarten Counting Game
*
*/

#include <bits/stdc++.h>

using namespace std;

bool isAword(string word){
	int j;
	for(j = 0; j < word.size(); j++){
		if( (word[j] >= 'A' && word[j] <= 'Z') || (word[j] >= 'a' && word[j] <= 'z') ){
			return true;
		}
	}

	return false;
}

int main(){
	string line, word;
	int i, count;

	while( getline(cin, line) ){
		i = 0;
		count = 0;
		word = "";
		for(i; i < line.size(); i++){
			if( (line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') ){
				word+=line[i];
			}else{
				if( line[i] == ' ' || i == line.size()-1 ){
					if( isAword(word) ){
						count++;
					}
					word = "";
				}
				if( isAword(word) ){
					count++;
				}
				word = "";
			}
		}

		printf("%d\n", count);

	}


	return 0;
}
