/*
*
* Problema UVA 12015 - Google is Feeling Lucky
*
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector< pair<string, int> > webs;
	vector< pair<string, int> >::iterator it;
	int cases, i, aux, higher, c = 0;
	string line;

	scanf("%d", &cases);

	while(cases--){
		c++;
		higher = 1;
		for(i = 0; i < 10; i++){
			cin >> line;
			scanf(" %d\n", &aux);
			webs.push_back( make_pair(line, aux) );
			if(aux >= higher){
				higher = aux;
			}
		}

		printf("Case #%d:\n", c);

		for(it = webs.begin(); it != webs.end(); ++it){
			if(it->second == higher){
				cout << it->first << endl;
			}
		}

		webs.clear();
	}

	return 0;
}