/*
*
* Problema UVA 10528 - Major Scales
*
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main(){
	vector< vector<string> > scales {
	 { "C", "D", "E", "F", "G", "A", "B" },
	 { "C#", "D#", "F", "F#", "G#", "A#", "C" },
	 { "D", "E", "F#", "G", "A", "B", "C#" },
	 { "D#", "F", "G", "G#", "A#", "C", "D" },
	 { "E", "F#", "G#", "A", "B", "C#", "D#" },
	 { "F", "G", "A", "A#", "C", "D", "E" },
	 { "F#", "G#", "A#", "B", "C#", "D#", "F" },
	 { "G", "A", "B", "C", "D", "E", "F#" },
	 { "G#", "A#", "C", "C#", "D#", "F", "G" },
	 { "A", "B", "C#", "D", "E", "F#", "G#" },
	 { "A#", "C", "D", "D#", "F", "G", "A" },
	 { "B", "C#", "D#", "E", "F#", "G#", "A#" },
	};
	vector<string> notes1;
	vector<string> notes2;
	vector<string> keys;
	vector<string> aux1;
	stringstream fill;
	string line, aux;
	int i, j, k, sum;

	while(1){
		getline(cin, line);
		if( line == "END" ){
			break;
		}else{
			stringstream fill(line);

			while( fill >> aux ){
				notes1.push_back( aux );
			}

			notes2 = notes1;

			for(i = 0; i < scales.size(); i++){
				sum = 0;
				notes1 = notes2;
				for(j = 0; j < notes1.size(); j++){
					for(k = 0; k < scales[i].size(); k++){
						if( notes1[j] == scales[i][k] ){
							sum++;
						}
					}
				}
				aux = scales[i][0];
				if(notes1.size() == sum){
					keys.push_back( aux );
				}
			}

			for( i = 0; i < keys.size(); i++ ){
				if( i > 0 ){
					cout << " ";
				}
				cout << keys[i];
			}
			cout << endl;

			notes1.clear();
			keys.clear();
		}
	}

  return 0;
}
