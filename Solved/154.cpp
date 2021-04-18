/*
*
* Problema UVA 154 - Recycling
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class City{
public:
	string red;
	string orange;
	string yellow;
	string green;
	string blue;
	int value;
	int num;

	City(string r, string o, string y, string g, string b, int n){
		red = r;
		orange = o;
		yellow = y;
		green = g;
		blue = b;
		num = n;
	}

	bool operator<(const City& c )const{
		return value > c.value;
	}

};

int main(){
	string line, r, o, y, g, b;
	vector<City> citys;
	vector<City>::iterator it;
	vector<City>::iterator it1;
	int i, c = 0;

	while( cin >> line ){
		if(line[0] == 'e'){
			/*Contar la cantidad de coincidencias*/
			for(it = citys.begin(); it != citys.end(); it++){
				for(it1 = citys.begin(); it1 != citys.end(); it1++){
					if( it->red == it1->red ){
						it->value++;
					}
					if( it->orange == it1->orange ){
						it->value++;
					}
					if( it->yellow == it1->yellow ){
						it->value++;
					}
					if( it->green == it1->green ){
						it->value++;
					}
					if( it->blue == it1->blue ){
						it->value++;
					}
				}
			}

			sort(citys.begin(), citys.end());
			it = citys.begin();

			printf("%d\n", it->num);


			c = 0;
			citys.clear();
		}else if(line == "#"){
			break;
		}else{
			c++;
			for(i = 0; i < line.size(); i++){
				if( line[i] == 'r' ){
					r = line[i+2];
				}
				else if( line[i] == 'o' ){
					o = line[i+2];
				}
				else if( line[i] == 'y' ){
					y = line[i+2];
				}
				else if( line[i] == 'g' ){
					g = line[i+2];
				}
				else if( line[i] == 'b' ){
					b = line[i+2];
				}
			}

			citys.push_back( City(r, o, y, g, b, c) );
		}
	}


	return 0;
}