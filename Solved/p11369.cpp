/*
*
* Problema UVA 11369 - Shopaholic
*
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
	return a > b;
}

int main(){
	int cases;
	int c, i, j, aux, disc;

	cin >> cases;

	while(cases--){
		cin >> c;

		vector<int> items;

		for(i = 0; i < c; i++){
			cin >> aux;
			items.push_back(aux);
		}

		sort(items.begin(), items.end(), comp);

		disc = 0;

		for(i = 0; i+2 < items.size(); i+=3){
			disc += items[i+2];
		}

		printf("%d\n", disc);

	}

	return 0;
}
