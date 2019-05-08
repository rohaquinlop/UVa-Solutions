/*Nombre de usuario: YouNIXnBits || https://uhunt.onlinejudge.org/id/1000203*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Persona{
public:
	string name;
	int d;
	int m;
	int y;

	Persona(string n, int a, int b, int c){
		name = n;
		d = a;
		m = b;
		y = c;
	}

	bool operator<(Persona p ){
		if( y != p.y ){
			return y > p.y;
		}else if( m != p.m ){
			return m > p.m;
		}
		return d > p.d;
	}

};

int main(){
	int n, i, d, m, y;
	string name;
	vector<Persona> personas;

	vector<Persona>::iterator it;

	scanf("%d\n", &n);

	for(i = 0; i < n; i++){
		cin >> name >> d >> m >> y;

		personas.push_back( Persona(name, d, m, y) );
	}


	sort(personas.begin(), personas.end());

	i = 0;
	for(it = personas.begin(); it != personas.end(); it++ ){
		if( i == 0 || i == n-1 ){
			cout << it->name << endl;
		}
		i++;
	}

	return 0;
}