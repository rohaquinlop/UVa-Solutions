/*
*
* Problema UVa 10282 - Babelfish
*
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	bool found; int i;
	string w1, w2, line;
	map<string, string> words;
	map<string, string>::iterator it;

	while( getline(cin, line) ){
		if(line == "")
			break;
		else{
			found = false;
			w1 = "", w2 = "";
			for(i = 0; i < line.size(); i++){
				if( line[i] == ' ' ){
					found = true;
				}else{
					if( !found )
						w1 += line[i];
					else
						w2 += line[i];
				}
			}
			words[w2] = w1;
		}
	}

	while( getline(cin, line) ){
		it = words.find(line);

		if( it != words.end() )
			cout << words[line] << endl;
		else
			cout << "eh" << endl;
	}

	return 0;
}