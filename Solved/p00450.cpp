/*
*
* Problema UVA 450 - Little Black Book
*
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Persona{
public:
	string title;
	string fName;
	string lName;
	string address;
	string dep;
	string hPhone;
	string wPhone;
	string cBox;

	Persona(string t, string f, string l, string a, string d, string h, string w, string c){
		title = t;
		fName = f;
		lName = l;
		address = a;
		dep = d;
		hPhone = h;
		wPhone = w;
		cBox = c;
	}

	bool operator <(const Persona& per)const{
		return lName < per.lName;
	}

};

int main(){
	int n, i;
	string dep, line;
	string t, f, l, a, d, h, w, c;

	scanf("%d\n", &n);

	vector <Persona> personas;
	vector <Persona>::iterator it;

	while(n--){
		getline(cin, dep);

		while( getline(cin, line) ){
			if( line.size() < 1 ){
				break;
			}else{
				t = "", f = "", l = "", a = "", d = dep, h = "", w = "", c = "";

				for(i = 0; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						t += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						f += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						l += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						a += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						h += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						w += line[i];
					}
				}

				for(i; i < line.size(); i++){
					if( line[i] == ',' ){
						i++;
						break;
					}else{
						c += line[i];
					}
				}

				personas.push_back( Persona(t, f, l, a, d, h, w, c) );

				sort(personas.begin(), personas.end());

			}
		}
	}

	for( it = personas.begin(); it != personas.end(); it++ ){
		printf("----------------------------------------\n");
		cout << it->title << " " << it->fName << " " << it->lName << "\n";
		cout << it->address << "\n";
		cout << "Department: " << it->dep << "\n";
		cout << "Home Phone: " << it->hPhone << "\n";
		cout << "Work Phone: " << it->wPhone << "\n";
		cout << "Campus Box: " << it->cBox << "\n";
	}


	return 0;
}