/*
*
* Problema UVA 1586 - Molar mass
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases, value, i;
	string line;
	double res;
	char element;

	cin >> cases;

	while(cases--){
		cin >> line;

		map<char, double> mol;

		mol['C'] = 12.01;
		mol['H'] = 1.008;
		mol['O'] = 16.00;
		mol['N'] = 14.01;

		res = 0;

		for(i = 0; i < line.size(); i++){
			element = line[i];
			value = 0;
			i++;

			while( line[i] >= '0' && line[i] <= '9' ){
				value = (value * 10) + line[i] - '0';
				i++;
			}
			if( value == 0 ){
				value = 1;
			}
			res += mol[element] * (double)value;
			i--;

		}

		printf("%.3lf\n", res);

	}


	return 0;
}
