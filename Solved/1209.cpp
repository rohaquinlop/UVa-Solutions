/*
*
* Problema UVA 1209 - Wordfish
*
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Letra{
public:
	string l;
	int dist;

	Letra( string a, int b ){
		l = a;
		dist = b;
	}

	bool operator <(const Letra& letra) const{
		if( dist != letra.dist ){
			return dist > letra.dist;
		}else{
			return l < letra.l;
		}
	}

};

int distance(string a){
	int dist = 26, i, v1, v2;
	
	for(i = 1; i < a.size(); i++){
		v1 = a[i-1] - '0';
		v2 = a[i] - '0';

		if( fabs(v1-v2) < dist ){
			dist = fabs(v1-v2);
		}
	}

	return dist;
}

int main(){
	string word, cp1;
	int dist, a, b, i, c;

	while(cin >> word){
		vector<Letra> perms;
		vector<Letra>::iterator it;
		perms.push_back( Letra(word, distance(word)) );
		c = 1;
		cp1 = word;

		while(next_permutation(word.begin(), word.end()) && c <= 10){
			perms.push_back( Letra(word, distance(word)) );
			c++;
		}

		c = 1;
		while(prev_permutation(cp1.begin(), cp1.end()) && c <= 10){
			perms.push_back( Letra(cp1, distance(cp1)) );
			c++;	
		}

		sort(perms.begin(), perms.end());

		Letra out = perms[0];

		cout << out.l << out.dist << "\n";

	}

	return 0;
}
