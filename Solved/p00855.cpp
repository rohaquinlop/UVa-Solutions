/*
*
* Problema UVA 855 - Lunch in Grid City
*
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases, mX, mY;
	int s, a, f, i, x, y, pos;

	cin >> cases;

	while(cases--){
		cin >> s >> a >> f;

		vector<int> streets;
		vector<int> avenues;

		for(i = 0; i < f; i++){
			cin >> x >> y;
			streets.push_back(x);
			avenues.push_back(y);
		}

		sort(streets.begin(), streets.end());
		sort(avenues.begin(), avenues.end());

		pos = (f-1)/2;

		printf("(Street: %d, Avenue: %d)\n", streets[pos], avenues[pos]);

	}


	return 0;
}
