/*
*
* Problema UVA 10424 - Love Calculator
*
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>

char easytolower(char in) {
  if(in <= 'Z' && in >= 'A')
    return in - ('Z' - 'z');
  return in;
}

int g(int n){
	int sum;
	while( n >= 10 ){
		sum = 0;

		while( n > 0 ){
			sum += n % 10;
			n /= 10;
		}

		n = sum;
	}

	return n;

}

using namespace std;

int main(){
	map<string, int> claves;

	claves["a"] = 1;
	claves["b"] = 2;
	claves["c"] = 3;
	claves["d"] = 4;
	claves["e"] = 5;
	claves["f"] = 6;
	claves["g"] = 7;
	claves["h"] = 8;
	claves["i"] = 9;
	claves["j"] = 10;
	claves["k"] = 11;
	claves["l"] = 12;
	claves["m"] = 13;
	claves["n"] = 14;
	claves["o"] = 15;
	claves["p"] = 16;
	claves["q"] = 17;
	claves["r"] = 18;
	claves["s"] = 19;
	claves["t"] = 20;
	claves["u"] = 21;
	claves["v"] = 22;
	claves["w"] = 23;
	claves["x"] = 24;
	claves["y"] = 25;
	claves["z"] = 26;

	string name1, name2, aux;
	float count1, count2, i, sum1, sum2;
	float div;

	while( getline(cin, name1) ){
		getline(cin, name2);

		transform(name1.begin(), name1.end(), name1.begin(), easytolower);
		transform(name2.begin(), name2.end(), name2.begin(), easytolower);

		count1 = 0;
		count2 = 0;
		sum1 = 0;
		sum2 = 0;

		for(i = 0; i < name1.length(); i++){
			aux = name1[i];
			count1 += claves[aux];
		}

		for(i = 0; i < name2.length(); i++){
			aux = name2[i];
			count2 += claves[aux];
		}

		sum2 = g(count2);
		sum1 = g(count1);

		div = min(sum1, sum2) / max(sum1, sum2) * 100;

		printf("%.2f %%\n", div);

	}
}