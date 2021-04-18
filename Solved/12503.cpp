/*
*
* Problema UVA 12503 - Robot Instructions
*
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> movements;
	int cases, n, as, pos;
	string line;

	cin >> cases;

	while(cases--){
		cin >> n;
		pos = 0;

		while(n--){
			cin >> line;

			if( line == "LEFT" ){
				pos--;
				movements.push_back(line);
			}else if( line == "RIGHT" ){
				pos++;
				movements.push_back(line);
			}else if( line == "SAME" ){
				cin >> line;
				scanf(" %d", &as);

				line = movements[as-1];
				if( line == "LEFT" ){
					pos--;
					movements.push_back(line);
				}else if( line == "RIGHT" ){
					pos++;
					movements.push_back(line);
				}
			}
		}

		cout << pos << endl;

		movements.clear();

	}

  return 0;
}
