/*
 *
 * Problema UVa 156 - Ananagrams
 *
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char easytolower(char in) {
	if(in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

map<string, int>::iterator findWord(map<string, int> m, string w){
	map<string, int>::iterator it;
	string cmp;

	for(it = m.begin(); it != m.end(); it++){
		cmp = it->first;
		transform( cmp.begin(), cmp.end(), cmp.begin(), easytolower);
		sort(cmp.begin(), cmp.end());
		if( w == cmp ){
			return it;
		}
	}
	return it;
}

int main(){
	map<string, int> words;
	map<string, int>::iterator it;
	string word, aux, cmp;

	while( cin >> word ){
		if( word == "#" )
			break;
		else{
			aux = word;
			transform( aux.begin(), aux.end(), aux.begin(), easytolower);
			sort(aux.begin(), aux.end());
			
			for(it = words.begin(); it != words.end(); it++){
				cmp = it->first;
				transform( cmp.begin(), cmp.end(), cmp.begin(), easytolower);
				sort(cmp.begin(), cmp.end());
				if( aux == cmp ){
					break;
				}
			}

			if( it == words.end() ){
				words[word] = 1;
			}else{
				(it->second)++;
			}
		}
	}

	for(it = words.begin(); it != words.end(); it++){
		if( it->second == 1 )
			cout << it->first << "\n";
	}


	return 0;
}