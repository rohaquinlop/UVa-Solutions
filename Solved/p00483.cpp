/*
*
* Problema UVA 483 - Word Scramble
*
*/

#include <bits/stdc++.h>

using namespace std;

void reverse(string str){
	for (int i=str.length()-1; i>=0; i--) 
		cout << str[i];  
} 

int main(){
	string line, word;
	int i;

	while( getline(cin, line) ){

		vector<string> revs;
		i = 0;
		word = "";

		for(i; i < line.size(); i++){
			if( line[i] != ' ' ){
				word += line[i];
			}else{
				reverse(word);
				printf(" ");
				word = "";
			}
		}
		reverse(word);
		printf("\n");

	}


	return 0;
}