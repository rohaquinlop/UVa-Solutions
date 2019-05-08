/*
*
* Problema UVA 482 - Permutation Arrays
*
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	int cases, i, j, count, c = 0;
	string line1, line2;

	scanf("%d\n",&cases);

	while(cases--){
		c++;
		getline(cin, line1);
		getline(cin, line2);
		
		count = 0;

		vector<string> arrPerm;
		vector<string> arrOrder;

		if( c > 1){
			cout << endl;
		}

		for(i = 0; i < line1.length(); i++) {
			if(isspace(line1[i])) {
			    if(count == 1) {
			        count = 0;
			    }else
			        count++;
			    continue;
			}
			j = i;
			string aux1 = "";
			while(!isspace(line1[j]) && j < line1.length()) {
			    aux1 += line1[j];
			    j++;
			}
			/* Añadir la palabra al arreglo */
			arrOrder.push_back(aux1);
			count = 0;
			i = j-1;
		}

		count = 0;
		for(i = 0; i < line2.length(); i++) {
			if(isspace(line2[i])) {
			    if(count == 1) {
			        count = 0;
			    }else
			        count++;
			    continue;
			}
			j = i;
			string aux2 = "";
			while(!isspace(line2[j]) && j < line2.length()) {
			    aux2 += line2[j];
			    j++;
			}
			/* Añadir la palabra al arreglo */
			arrPerm.push_back(aux2);
			count = 0;
			i = j-1;
		}

		for(j = 0; j < arrOrder.size(); j++){
			for(i = 0; i < arrOrder.size(); i++){
				const char* pos = arrOrder[i].c_str();
				int num = atoi(pos);
				if(num == j+1){
					cout << arrPerm[i] << endl;
				}
			}
		}

		getline(cin, line1);
	}


	return 0;
}
